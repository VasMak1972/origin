#include <iostream>       // std::cout
#include <functional>     // std::ref
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath> 
#include "shape.h"





Shape::Shape(int type, int x1, int y1, int z1, int x2, int y2, int z2, int x3, int y3, int z3, int x4, int y4, int z4, int x5, int y5, int z5, int x6, int y6, int z6, int x7, int y7, int z7, int x8, int y8, int z8) :
    type(type), x1(x1), y1(y1), z1(z1), x2(x2), y2(y2), z2(z2), x3(x3), y3(y3), z3(z3), x4(x4), y4(y4), z4(z4), x5(x5), y5(y5), z5(z5), x6(x6), y6(y6), z6(z6), x7(x7), y7(y7), z7(z7), x8(x8), y8(y8), z8(z8)
{
}
Shape::Shape(int type, int x1, int y1, double R, double H) : type(type), x1(x1), y1(y1), R(R), H(H) {}


// стороны фигуры  !!!
//int a = abs(x1 - x2); 
//int b = abs(y1 - y2);
//int c = abs(z1 - z2);

class lines : public Shape
{
public:
    lines(int _x1, int _y1, int _x2, int _y2) : Shape(0, _x1, _y1, 0, _x2, _y2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0) {}

    int a() { return  abs(x1 - x2); }

    int square() { return 0; }
    int volume() { return 0; }

    //int square() override { return 0; }
    //int volume() override { return 0; }
};


class sqrs : public Shape
{
public:
    sqrs(int _x1, int _y1, int _x2, int _y2, int _x3, int _y3, int _x4, int _y4) :
        Shape(Shape::sqr, _x1, _y1, 0, _x2, _y2, 0, _x3, _y3, 0, _x4, _y4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0) {
    }

    int a() { return  abs(x1 - x2); }
    int b() { return  abs(y1 - y2); }

    int square() { return a() * b(); }
    int volume() { return 0; }

    //int square() override { return a() * b(); }
    //int volume() override { return 0; }
};

class cubes : public Shape
{
public:
    cubes(int _x1, int _y1, int _z1, int _x2, int _y2, int _z2, int _x3, int _y3, int _z3, int _x4, int _y4, int _z4, int _x5, int _y5, int _z5, int _x6, int _y6, int _z6, int _x7, int _y7, int _z7, int _x8, int _y8, int _z8) :
        Shape(Shape::cube, _x1, _y1, _z1, _x2, _y2, _z2, _x3, _y3, _z3, _x4, _y4, _z4, _x5, _y5, _z5, _x6, _y6, _z6, _x7, _y7, _z7, _x8, _y8, _z8) {
    }

    int a() { return  abs(x1 - x2); }
    int b() { return  abs(y1 - y2); }
    int c() { return  abs(z1 - z2); }

    int square() { return 2 * (a() * b() + a() * c() + b() * c()); }
    int volume() { return a() * b() * c(); }

    //int square() override { return 2 * (a() * b() + a() * c() + b() * c()); }
    //int volume() override { return a() * b() * c(); }
};

class circles : public Shape
{
public:
    circles(int _x1, int _y1, int _R) : Shape(Shape::circle, _x1, _y1, _R, 0) {}

    int square() { return PI * R * R; }
    int volume() { return 0; }

    //int square() override { return PI * R * R; }
    //int volume() override { return 0; }
};

class cylinders : public Shape
{
public:
    cylinders(int _x1, int _y1, int _R, int _H) : Shape(Shape::cylinder, _x1, _y1, _R, _H) {}

    int square() { return  PI * R * R + 2 * R * H; }
    int volume() { return PI * R * R * H; }

    //int square() override { return 2 * PI * R * (R + H); }
     //int volume() override { return PI * R * R * H; }
};







int main() {

    Shape* shp;

    lines line(5, 5, 15, 15);
    sqrs sqr(0, 0, 5, 5, 0, 5, 5, 0);
    cubes cube(0, 0, 0, 5, 5, 5, 0, 5, 0, 0, 0, 5, 5, 5, 0, 5, 0, 5, 0, 5, 5, 5, 0, 0);
    circles circle(0, 0, 5);
    cylinders cylinder(10, 10, 5, 10);

    std::cout << "Area line: " << line.square() << std::endl;
    std::cout << "Area square: " << sqr.square() << std::endl;
    std::cout << "Area cube: " << cube.square() << std::endl;
    std::cout << "Area circle: " << circle.square() << std::endl;
    std::cout << "Area cylinder: " << cylinder.square() << std::endl;
    std::cout << std::endl;


    std::cout << "Coordinates line:" << std::endl;
    std::cout << "(" << line.x1 << ", " << line.y1 << ", " << line.z1 << ")" << std::endl;
    std::cout << "(" << line.x2 << ", " << line.y2 << ", " << line.z2 << ")" << std::endl;

    shp = &line;
    Shape trans(shp); // Create a transform object
    shp = trans.Shape::scaleX(10);
    shp = trans.Shape::scaleY(10);
    shp = trans.Shape::scaleZ(10);

    std::cout << "Changed coordinates line:" << std::endl;
    std::cout << "(" << line.x1 << ", " << line.y1 << ", " << line.z1 << ")" << std::endl;
    std::cout << "(" << line.x2 << ", " << shp->y2 << ", " << shp->z2 << ")" << std::endl;


    std::cout << std::endl;

    /*
    int main () { // before refactoring

    Shape line(0,  5, 5, 0,  15, 15, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    Shape sqr(1, 0, 0, 0,  5, 5, 0,  5, 0, 0,  0, 5, 0,  0, 0, 0,  0, 0, 0,  0, 0, 0,  0, 0, 0);
    Shape cube(2, 0, 0, 0,  5, 5, 5,  0, 5, 0,  0, 0, 5,  5, 5, 0,  5, 0, 5,  0, 5, 5,  5, 0, 0);

    Shape circle(3, 10, 10, 5, 0);
    Shape cylinder(4, 10, 10, 5, 10);

    std::cout << "Area line: " << line.line << std::endl;
    std::cout << "Area square: " << sqr.square << std::endl;
    std::cout << "Area cube: "<< cube.square << std::endl;
    std::cout << "Area circle: " << circle.square << std::endl;
    std::cout << "Area cylinder: " << cylinder.square << std::endl;
    std::cout << std::endl;


    std::cout << "Coordinates line:" << std::endl;
    std::cout <<"("<< line.x1 << ", " << line.y1 << ", " << line.z1 << ")" << std::endl;
    std::cout <<"("<< line.x2 << ", " << line.y2 << ", " << line.z2 << ")" << std::endl;

    transform trans(std::ref(line)); // Create a transform object
    line = trans.transform::scaleX(10); // Use sqr as input to the transform object
    line = trans.transform::scaleY(10);
    line = trans.transform::scaleZ(10);

    std::cout << "Changed coordinates line:" << std::endl;
    std::cout <<"("<< line.x1 << ", " << line.y1 << ", " << line.z1 << ")" << std::endl;
    std::cout <<"("<< line.x2 << ", " << line.y2 << ", " << line.z2 << ")" << std::endl;


    // console output

    Area line: 0
    Area square: 25
    Area cube: 150
    Area circle: 78.5397
    Area cylinder: 178.54

    Coordinates line:
    (5, 5, 0)
    (15, 15, 0)
    Changed coordinates line:
    (50, 50, 0)
    (150, 150, 0)
    */



    std::cout << "Hello! World!" << std::endl;
    return 0;

}
