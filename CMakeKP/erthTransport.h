#pragma once
#include <iostream>
#include <string>
#include "transport.h"

//НАЗЕМНЫЙ ТРАНСПОРТ
class ErthTransport : public Transport {
protected:
    int time_trvel;
    int time_out_1;
    int time_out_3;
    double time_out_2;

public:
    ErthTransport() : Transport() {
        name = "Наземный транспорт";
        time_trvel = 1;
        time_out_1 = 0;
        time_out_2 = 0;
        time_out_3 = 0;
    }

    void print() override;

    double race(int distance) override;
};

//Кентавр
class Kentavr : public ErthTransport {
public:
    Kentavr() : ErthTransport() {
        name = "Кентавр";
        speed = 15;
        time_trvel = 8;
        time_out_1 = 2;
    }
};

//Верблюд
class Camel : public ErthTransport {
public:
    Camel() : ErthTransport() {
        name = "Верблюд";
        speed = 10;
        time_trvel = 30;
        time_out_1 = 5;
        time_out_2 = 8;
    }
    double race(int distance) override;
};

//Ботинки-вездеходы
class Boots : public ErthTransport {

public:
    Boots() : ErthTransport() {
        name = "Ботинки-вездеходы";
        speed = 6;
        time_trvel = 60;
        time_out_1 = 10;
        time_out_2 = 5;
    }

    double race(int distance) override;
};

//Верблюд - быстроход
class CamelFast : public Camel {

public:
    CamelFast() : Camel() {
        name = "Верблюд-быстроход";
        speed = 40;
        time_trvel = 10;
        time_out_2 = 6.5;
        time_out_3 = 8;
    }

    double race(int distance) override;
};
