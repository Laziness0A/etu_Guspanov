#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
#include <iostream>

int pos = 0; 
bool realdate = false;

void Menu() {
    char menu[3][41] = {"1.Ввести Дату Рождения", "2.Вывести Аркан", "3.Выход"};
    char marker[5] = "<---";
    
    for (int i = 0; i < 3; ++i) {
        printf("%s", menu[i]);
        if (i == pos) {
            printf("  %s", marker);
        }
        printf("\n");
    }
}

struct Date {
    int day;
    int month;
    int year;
};

struct Date dt;

void inputDate(struct Date* dt) {
    char input[1000];
    printf("Введите дату (ДД.ММ.ГГГГ): ");
    scanf("%s", input);

    sscanf(input, "%d.%d.%d", &dt->day, &dt->month, &dt->year);
}

int arcanaschet(struct Date dt) {
    int arcan = (dt.day / 10) + (dt.day % 10);
    arcan += (dt.month / 10) + (dt.month % 10);
    arcan += (dt.year / 1000) + ((dt.year % 1000) / 100) + ((dt.year % 100) / 10) + (dt.year % 10);
    
    if (arcan > 22) {
        arcan -= 22;
    }
    
    return arcan;
}

// Оптимизированная версия функции проверки даты
void validateDate(struct Date dt) {
    int daysInMonths[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    if (dt.year % 4 == 0 && (dt.year % 100 != 0 || dt.year % 400 == 0)) {
        daysInMonths[1] = 29;  // Високосный год
    }

    // Проверяем корректность месяца и дня
    if (dt.month > 0 && dt.month <= 12 && dt.day > 0 && dt.day <= daysInMonths[dt.month - 1]) {
        realdate = true;
    } else {
        realdate = false;
    }
}

void checkRealDate(struct Date dt) {
    if (dt.year > 0 && dt.month > 0 && dt.month <= 12) {
        if (dt.day > 0 && arcanaschet(dt) < 45) {
            validateDate(dt);
        }
    }
}

void handleAction(int funct) {
    switch (funct) {
        case 0:
            printf("\e[1;1H\e[2J");
            inputDate(&dt);
            checkRealDate(dt);
            if (!realdate) {
                printf("Недопустимый ввод. (чтобы продолжить работу нажмите enter)\n");
                while (getch() != 13) {}
            }
            break;
        case 1:
            printf("\e[1;1H\e[2J");
            if (realdate) {
                printf("У вас %d аркан. (чтобы продолжить работу нажмите enter)", arcanaschet(dt));
                while (getch() != 13) {}
            } else {
                printf("Вашей даты рождения не существует. (чтобы продолжить работу нажмите enter)\n");
                while (getch() != 13) {}
            }
            break;
        default:
            break;
    }
}

int main() {
    int input;
    while (true) {
        Menu();
        input = getch();
        
        if (input == 49) {
            pos = 0;
        } else if (input == 50) {
            pos = 1;
        } else if (input == 51) {
            pos = 2;
        } else if (input == 13) {
            if (pos == 2) {
                printf("\e[1;1H\e[2J");
                return 0;
            } else {
                handleAction(pos);
            }
        } else if (input == 224) {
            input = getch();
            if (input == 72) {
                pos--;
                if (pos < 0) pos = 2;
            } else if (input == 80) {
                pos++;
                if (pos > 2) pos = 0;
            }
        }

        printf("\e[1;1H\e[2J");
    }

    return 0;
}
