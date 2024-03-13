#pragma once
#include <iostream>
#include <string>
#include "transport.h"

//�������� ���������
class ErthTransport : public Transport {
protected:
    int time_trvel;
    int time_out_1;
    int time_out_3;
    double time_out_2;

public:
    ErthTransport() : Transport() {
        name = "�������� ���������";
        time_trvel = 1;
        time_out_1 = 0;
        time_out_2 = 0;
        time_out_3 = 0;
    }

    void print() override;

    double race(int distance) override;
};

//�������
class Kentavr : public ErthTransport {
public:
    Kentavr() : ErthTransport() {
        name = "�������";
        speed = 15;
        time_trvel = 8;
        time_out_1 = 2;
    }
};

//�������
class Camel : public ErthTransport {
public:
    Camel() : ErthTransport() {
        name = "�������";
        speed = 10;
        time_trvel = 30;
        time_out_1 = 5;
        time_out_2 = 8;
    }
    double race(int distance) override;
};

//�������-���������
class Boots : public ErthTransport {

public:
    Boots() : ErthTransport() {
        name = "�������-���������";
        speed = 6;
        time_trvel = 60;
        time_out_1 = 10;
        time_out_2 = 5;
    }

    double race(int distance) override;
};

//������� - ���������
class CamelFast : public Camel {

public:
    CamelFast() : Camel() {
        name = "�������-���������";
        speed = 40;
        time_trvel = 10;
        time_out_2 = 6.5;
        time_out_3 = 8;
    }

    double race(int distance) override;
};
