#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
#include <iostream>
#include <fstream>
#include <chrono>
#include "C:\Users\Lazzy\Desktop\Prg\firstrepo\ArcanLibrary.cpp" // НЕ ВИДИТ H ФАЙЛ ПОЧЕМУ НЕ ПОНЯТНО ВИДИТ ТОЛЬКО ТАК И ВТОРУЮ БИБЛИОТЕКУ ТОЖЕ

int main() {
    #ifdef ARCAN_LIBRARY_H
        keyWork();
    #else
        std::cout << "НЕ ПАШЕТ ;(" << std::endl;
    #endif
    return 0;
}



