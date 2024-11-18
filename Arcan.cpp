#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
#include <iostream>
#include <fstream>
#include <chrono>
#include <ArcanLibrary.h>



int main() {
    #ifdef ARCAN_LIBRARY_WORK
        keyWork();
    #else
        std::cout << "НЕ ПАШЕТ ;(" << std::endl;
    #endif
    return 0;
}
