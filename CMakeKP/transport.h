#pragma once
#include <iostream>
#include <string>

//������������ ��������
class Transport {
protected:
    std::string name;
    int speed;

public:
    Transport();

    virtual void print();

    virtual double race(double distance);

    std::string getNameTransport();
};