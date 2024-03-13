#pragma once
#include <iostream>
#include <string>

//ТИПЫ ТРАНСПОРТНЫХ СРЕДСТВ
// В с е   т и п ы
class AllTypes {
public:
    std::string boots;
    std::string broom;
    std::string camel;
    std::string kentavr;
    std::string eagle;
    std::string camel_fast;
    std::string carpet;

public:
    AllTypes() {
        boots = "Ботинки-вездеходы";
        broom = "Метла";
        camel = "Верблюд";
        kentavr = "Кентавр";
        eagle = "Орел";
        camel_fast = "Верблюд-быстроход";
        carpet = "Ковер-самолет";
    }

    void print_list() {
        std::cout << "1. " << boots << '\n';
        std::cout << "2. " << broom << '\n';
        std::cout << "3. " << camel << '\n';
        std::cout << "4. " << kentavr << '\n';
        std::cout << "5. " << eagle << '\n';
        std::cout << "6. " << camel_fast << '\n';
        std::cout << "7. " << carpet << '\n';
        std::cout << "0. Закончить регистрацию\n";
    }
};


//Н а з е м н ы й   т и п
class EarhTypes : public AllTypes {
public:
    EarhTypes() : AllTypes() {
        broom = "Неопределен";
        eagle = "Неопределен";
        carpet = "Неопределен";
    }
};


//В о з д у ш н ы й   т и п
class AirTypes : public AllTypes {
public:
    AirTypes() : AllTypes() {
        boots = "Неопределен";
        camel = "Неопределен";
        kentavr = "Неопределен";
        camel_fast = "Неопределен";
    }
};