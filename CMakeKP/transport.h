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

    virtual double race(int distance);

    std::string getNameTransport();
};