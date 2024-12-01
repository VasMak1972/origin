// vasmak100.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
//
#include <iostream>       // std::cout
#include <functional>     // std::ref
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath> 
#include "shape.h"
#include "transform.h"

Shape::Shape(int _type, int _x1, int _y1, int _z1, int _x2, int _y2, int _z2, int _x3, int _y3, int _z3, int _x4, int _y4, int _z4, int _x5, int _y5, int _z5, int _x6, int _y6, int _z6, int _x7, int _y7, int _z7, int _x8, int _y8, int _z8)
{
    type = _type;
    // заполн¤ем координаты фигуры
    switch (type)
    {
    case line:
        x1 = _x1; y1 = _y1;
        x2 = _x2; y2 = _y2;
        break;
    case sqr:
        x1 = _x1; y1 = _y1;
        x2 = _x2; y2 = _y2;
        x3 = _x3; y3 = _y3;
        x4 = _x4; y4 = _y4;
        break;
    case cube:
        x1 = _x1; y1 = _y1; z1 = _z1;
        x2 = _x2; y2 = _y2; z2 = _z2;
        x3 = _x3; y3 = _y3; z3 = _z3;
        x4 = _x4; y4 = _y4; z4 = _z4;
        x5 = _x5; y5 = _y5; z5 = _z5;
        x6 = _x6; y6 = _y6; z6 = _z6;
        x7 = _x7; y7 = _y7; z7 = _z7;
        x8 = _x8; y8 = _y8; z8 = _z8;
        break;
    default:
        break;
    }

    // стороны фигуры
    int a = abs(x1 - x2);
    int b = abs(y1 - y2);
    int c = abs(z1 - z2);
    // считаем площадь фигуры
    switch (type)
    {
    case line:
        square = 0;
        break;
    case sqr:
        square = a * b;
        break;
    case cube:
        square = 2 * a * b + 2 * a * c + 2 * b * c;
        break;
    default:
        break;
    }
    // считаем объем фигуры
    switch (type)
    {
    case line:
        volume = 0;
        break;
    case sqr:
        volume = 0;
        break;
    case cube:
        volume = a * b * c;
        break;
    default:
        break;
    }

}

Shape::Shape(int type, int _x1, int _y1, double R, double H)
{
    // заполн¤ем координаты фигуры
    switch (type)
    {
    case circle:
        x1 = _x1; y1 = _y1;
        radius = R;
        break;
    case cylinder:
        x1 = _x1; y1 = _y1;
        radius = R;
        height = H;
        break;
    default:
        break;
    }

    // считаем площадь фигуры
    switch (type)
    {
    case circle:
        square = M_PI * R * R;
        break;
    case cylinder:
        square = M_PI * R * R + 2 * R * height;
        break;
    default:
        break;
    }

    // считаем объем фигуры
    switch (type)
    {
    case circle:
        volume = 0;
        break;
    case cylinder:
        volume = M_PI * R * R * height;
        break;
    default:
        break;
    }

}

int main() {
    // creating class elements Shape
    Shape liniy(0, 5, 5, 0, 15, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    Shape sqr(1, 0, 0, 0, 5, 5, 0, 5, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    Shape cube(2, 0, 0, 0, 5, 5, 5, 0, 5, 0, 0, 0, 5, 5, 5, 0, 5, 0, 5, 0, 5, 5, 5, 0, 0);

    std::cout << liniy.line << std::endl;
    std::cout << sqr.square << std::endl;
    std::cout << cube.volume << std::endl;
    std::cout << std::endl;

    Shape circle(3, 10, 10, 5, 0);
    Shape cylinder(4, 10, 10, 5, 10);

    std::cout << circle.square << std::endl;
    std::cout << cylinder.volume << std::endl;

    // transformation class elemets
    transform trans(std::ref(sqr)); // Create a transform object

    sqr = trans.transform::scaleX(10); // Use sqr as input to the transform object
    sqr = trans.transform::scaleY(10);
    sqr = trans.transform::scaleZ(10);

    std::cout << std::endl;
    std::cout << sqr.x2 << std::endl;
    std::cout << sqr.y2 << std::endl;
    std::cout << sqr.z2 << std::endl;

    std::cout << std::endl;
    std::cout << sqr.square << std::endl;

    return 0;

}
