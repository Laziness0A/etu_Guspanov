#define CATCH_CONFIG_MAIN 

#include "C:\Users\Lazzy\Desktop\Prg\firstrepo\ArcanLibrary.cpp"
#include "C:\Users\Lazzy\Desktop\Prg\firstrepo\catch_amalgamated.hpp"
#include "C:\Users\Lazzy\Desktop\Prg\firstrepo\catch_amalgamated.cpp"
#include <fstream>
#include <string>

TEST_CASE("Проверка допустимых значений") {
    Date normDate = {15, 8, 2007};
    validateDate(normDate);
    REQUIRE(realdate == true); 
}

TEST_CASE("Проверка недопустимых значений") {
    Date neNormDate = {32, 12, 2023}; // Некорректный день
    validateDate(neNormDate);
    REQUIRE(realdate == false);

    neNormDate = {15, 13, 2023}; // Некорректный месяц
    validateDate(neNormDate);
    REQUIRE(realdate == false);

    neNormDate = {0, 8, 1995}; // Некорректный день (0)
    validateDate(neNormDate);
    REQUIRE(realdate == false);

    neNormDate = {2, 12, 9999}; // Общий аркан > 45
    checkRealDate(neNormDate);
    REQUIRE(realdate == false);

}


TEST_CASE("Проверка граничных значений диапазона") {
    Date minDate = {1, 1, 1};
    validateDate(minDate);
    REQUIRE(realdate == true);
}

TEST_CASE("Проверка правильности расчетов арканов") {
    Date date = {1, 1, 2001};
    REQUIRE(arcanaschet(date) == 5); 

    date = {1, 1, 2000};
    REQUIRE(arcanaschet(date) == 4); 
}


TEST_CASE("Проверка записи данных в файл") {
    dt = {15, 8, 1995};
    recordFiles(); 


    std::ifstream log("log.txt");
    REQUIRE(log.is_open()); 

    std::string lastLine;
    while (std::getline(log, lastLine)) {} 

    REQUIRE(lastLine == "15.8.1995"); 
    log.close();
}

