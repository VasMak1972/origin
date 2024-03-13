#pragma once
#include <iostream>
#include <string>

//倚劳严涡彝闻 研拍岩挛
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