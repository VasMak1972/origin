#pragma once
#include <iostream>
#include <string>
#include "transport.h"

//ВОЗДУШНЫЙ ТРАНСПОРТ
class AirTransport : public Transport {
protected:
    double factor;

public:
    AirTransport() : Transport() {
        name = "Воздушный транспорт";
        factor = 1;
    }
    void print() override;

    double race(double distance) override;
};

//О р е л
class Eagle : public AirTransport {

public:
    Eagle() : AirTransport() {
        name = "Орел";
        speed = 8;
        factor = 0.94;
    }
};


//Ковер-самолет
class Carpet_fly : public AirTransport {

public:
    Carpet_fly() : AirTransport() {
        name = "Ковер-самолет";
        speed = 10;
    }
    double race(double distance) override;
};

//М е т л а
class Broom : public AirTransport {

public:
    Broom() : AirTransport() {
        name = "Метла";
        speed = 20;
    }
    double race(double distance) override;
};