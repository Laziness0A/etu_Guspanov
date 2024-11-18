#ifndef ARCAN_LIBRARY_H   
#define ARCAN_LIBRARY_H

#define ARCAN_LIBRARY_WORK

struct Date {
    int day;
    int month;
    int year;
};



extern struct Date dt;
extern bool realdate;

// Функции
void resetDate();
void Menu();
void inputDate(struct Date* dt);
int arcanaschet(struct Date dt);
void validateDate(struct Date dt);
void checkRealDate(struct Date dt);
void recordFiles();
void description(int arcan);
void handleAction(int funct);
void keyWork();

#endif 
