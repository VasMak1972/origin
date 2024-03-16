#pragma once
#include <iostream>
#include <string>
#include "transport.h"

//��������� ���������
class AirTransport : public Transport {
protected:
    double factor;

public:
    AirTransport() : Transport() {
        name = "��������� ���������";
        factor = 1;
    }
    void print() override;

    double race(double distance) override;
};

//� � � �
class Eagle : public AirTransport {

public:
    Eagle() : AirTransport() {
        name = "����";
        speed = 8;
        factor = 0.94;
    }
};


//�����-�������
class Carpet_fly : public AirTransport {

public:
    Carpet_fly() : AirTransport() {
        name = "�����-�������";
        speed = 10;
    }
    double race(double distance) override;
};

//� � � � �
class Broom : public AirTransport {

public:
    Broom() : AirTransport() {
        name = "�����";
        speed = 20;
    }
    double race(double distance) override;
};