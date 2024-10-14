#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
#include <iostream>

int pos = 0; 
bool realdate = false;
// функция для печати псевдоменюшки
void menu() {
    char Menu[3][41] = {"1.Ввести Дату Рождения","2.Вывести Аркан","3.Выход"};
    char marker[5] = "<---";
    for (int i = 0; i < 3; ++i) {
        printf("%s", Menu[i]);
        if (i == pos) {
            printf("  %s", marker); // если pos == i то печатает стрелочку
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

// Функция для ввода даты
void inputDate(struct Date* dt) {
    char input[10];
    printf("Введите дату (ДД.ММ.ГГГГ): ");
    scanf("%s", input);

    sscanf(input, "%d.%d.%d", &dt->day, &dt->month, &dt->year);
}

int Arcanaschet(struct Date dt) {
    int arcan = (dt.day / 10) + (dt.day % 10); // сначала 1 цифру потом вторую 
    arcan += (dt.month / 10) + (dt.month % 10);
    arcan += (dt.year / 1000) + ((dt.year % 1000) / 100 ) + ((dt.year % 100) / 10 ) + (dt.year % 10);
    if (arcan > 22) {
        arcan -=22;
    }
    return arcan;
}

void prov(int funct,struct Date dt) {
    int m1 = 31;
    int m2 = 28;
    int m3 = 31;
    int m4 = 30;
    int m5 = 31;
    int m6 = 30;
    int m7 = 31;
    int m8 = 31;
    int m9 = 30;
    int m10 = 31;
    int m11= 30;
    int m12 = 31;
    if (dt.year% 4 == 0 && (dt.year % 100 != 0 || dt.year % 400 == 0)){
        m2 = 29;}
    switch (funct) {
        case 1: {
            if (dt.day <= m1){
                realdate = true;
            }}
            break;
        case 2: {
            if (dt.day <= m2){
                realdate = true;
            }}
            break;
        case 3: {
            if (dt.day <= m3){
                realdate = true;
            }}
            break;
        case 4: {
            if (dt.day <= m4){
                realdate = true;
            }}
            break;
        case 5: {
            if (dt.day <= m5){
                realdate = true;
            }}
            break;
        case 6: {
            if (dt.day <= m6){
                realdate = true;
            }}
            break;
        case 7: {
            if (dt.day <= m7){
                realdate = true;
            }}
            break;
        case 8: {
            if (dt.day <= m8){
                realdate = true;
            }}
            break;
        case 9: {
            if (dt.day <= m9){
                realdate = true;
            }}
            break;
        case 10: {
            if (dt.day <= m10){
                realdate = true;
            }}
            break;
        case 11: {
            if (dt.day <= m11){
                realdate = true;
            }}
            break;
        case 12: {
            if (dt.day <= m12){
                realdate = true;
            }
            break;}}

    }

//{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
void Realdate(struct Date dt) {
    if (dt.year > 0){
        if (dt.month > 0 && dt.month <= 12){
            prov(dt.month,dt);
        }
    }
}

void WHATDO(int funct){ //Название говорит за себя
    switch (funct) {
        case 0: {
            printf("\e[1;1H\e[2J");
            inputDate(&dt);
            Realdate(dt);
            if (realdate == false) {
                printf("Недопустимый ввод.(чтобы продолжить работу нажмите enter)\n");
                while (getch()!=13){}}
        }
        break;
        case 1: {
            printf("\e[1;1H\e[2J");
            if (realdate == true) {
                printf("У вас %d аркан.(чтобы продолжить работу нажмите enter)",Arcanaschet(dt));
                while (getch()!=13){}}
            else {
                printf("Вашей даты рождения не существует.(чтобы продолжить работу нажмите enter)\n");
                while (getch()!=13){}}

        }
        break;
        default: {
        }
        break;
}}

int main() {
    setlocale(LC_ALL, "Russian");
    int inpuT;
    while (1) {
        menu();
        inpuT = getch();
        if (inpuT == 49) {
            pos = 0;
        } else if (inpuT == 50) {
            pos = 1;
        } else if (inpuT == 27) {
            printf("\e[1;1H\e[2J");
            return 0;
        } else if (inpuT == 51) {
            pos = 2;
        } else if (inpuT == 27) {
            printf("\e[1;1H\e[2J");
            return 0;
        } else if (inpuT == 13) {
            if (pos == 2) {
                printf("\e[1;1H\e[2J");
                return 0;
            } else {
                WHATDO(pos);
            }
        } else if (inpuT == 224) {
            inpuT = getch();
            if (inpuT == 72) {
                pos--;
                if(pos < 0){
                    pos = 2;
                }
            }
            else if (inpuT == 80) {
                pos++;
                if(pos > 2){
                    pos = 0;
                }
            }}
          else {
            WHATDO(pos);
        }

        printf("\e[1;1H\e[2J");}

    return 0;
}