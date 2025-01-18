#pragma once
#include <iostream>       // std::cout
#include <functional>     // std::ref
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

class Geometry
{
protected:
    const double PI = 3.14159;

public:
    //virtual int square() = 0;
    //virtual int volume() = 0;
};


class Shape : public Geometry {
private:
    Shape* shp;

public:
    static const int line = 0;
    static const int sqr = 1;
    static const int cube = 2;
    static const int circle = 3;
    static const int cylinder = 4;

    int type;
    int x1, y1, z1,
        x2, y2, z2,
        x3, y3, z3,
        x4, y4, z4,
        x5, y5, z5,
        x6, y6, z6,
        x7, y7, z7,
        x8, y8, z8;
    double R, H;


    Shape() = default;

    Shape(Shape* shp) : shp(shp) {}

    Shape(int _type, int _x1, int _y1, int _z1, int _x2, int _y2, int _z2, int _x3, int _y3, int _z3, int _x4, int _y4, int _z4, int _x5, int _y5, int _z5, int _x6, int _y6, int _z6, int _x7, int _y7, int _z7, int _x8, int _y8, int _z8);

    Shape(int _type, int _x1, int _y1, double _R, double _H);

    Shape& operator=(Shape& other) {
        if (this == &other) {
            return *this;
        }
        Shape s = other;
        other = *this;
        *this = s;
        return *this;
    }



    Shape(Shape& sh)
    {
        *this = sh;
    }

    int getType() { return type; }

    Shape* shift(int m, int n, int k);
    Shape* scaleX(int a);
    Shape* scaleY(int d);
    Shape* scaleZ(int e);
    Shape* scale(int s);

    //int square() override = 0;
    //int volume() override = 0;

};


Shape* Shape::shift(int m, int n, int k)
{
    switch (shp->getType())
    {
    case Shape::line:
        shp->x1 += m; shp->y1 += n;
        shp->x2 += m; shp->y2 += n;
        break;

    case Shape::sqr:
        shp->x1 += m; shp->y1 += n;
        shp->x2 += m; shp->y2 += n;
        shp->x3 += m; shp->y3 += n;
        shp->x4 += m; shp->y4 += n;
        break;

    case Shape::cube:
        shp->x1 += m; shp->y1 += n; shp->z1 += k;
        shp->x2 += m; shp->y2 += n; shp->z2 += k;
        shp->x3 += m; shp->y3 += n; shp->z3 += k;
        shp->x4 += m; shp->y4 += n; shp->z4 += k;
        shp->x5 += m; shp->y5 += n; shp->z5 += k;
        shp->x6 += m; shp->y6 += n; shp->z6 += k;
        shp->x7 += m; shp->y7 += n; shp->z7 += k;
        shp->x8 += m; shp->y8 += n; shp->z8 += k;
        break;
    }
    return shp;
}

Shape* Shape::scaleX(int a)
{
    switch (shp->getType())
    {
    case Shape::line:
        shp->x1 *= a;
        shp->x2 *= a;        
        break;

    case Shape::sqr:
        shp->x1 *= a;
        shp->x2 *= a;
        shp->x3 *= a;
        shp->x4 *= a;          
        break;

    case Shape::cube:
        shp->x1 *= a;
        shp->x2 *= a;
        shp->x3 *= a;
        shp->x4 *= a;
        shp->x5 *= a;
        shp->x6 *= a;
        shp->x7 *= a;
        shp->x8 *= a;
        break;
    }
    return shp;
}

Shape* Shape::scaleY(int d)
{
    switch (shp->getType())
    {
    case Shape::line:
        shp->y1 *= d;
        shp->y2 *= d;
        break;

    case Shape::sqr:
        shp->y1 *= d;
        shp->y2 *= d;
        shp->y3 *= d;
        shp->y4 *= d;         
        break;

    case Shape::cube:
        shp->y1 *= d;
        shp->y2 *= d;
        shp->y3 *= d;
        shp->y4 *= d;
        shp->y5 *= d;
        shp->y6 *= d;
        shp->y7 *= d;
        shp->y8 *= d;
        break;
    }
    return shp;
}

Shape* Shape::scaleZ(int e)
{
    switch (shp->getType())
    {
    case Shape::line:
        shp->z1 *= e;
        shp->z2 *= e;
        break;

    case Shape::sqr:
        shp->z1 *= e;
        shp->z2 *= e;
        shp->z3 *= e;
        shp->z4 *= e;           
        break;

    case Shape::cube:
        shp->z1 *= e;
        shp->z2 *= e;
        shp->z3 *= e;
        shp->z4 *= e;
        shp->z5 *= e;
        shp->z6 *= e;
        shp->z7 *= e;
        shp->z8 *= e;
        break;
    }
    return shp;
}

Shape* Shape::scale(int s)
{
    switch (shp->getType())
    {
    case Shape::line:
        shp->x1 /= s; shp->y1 /= s;
        shp->x2 /= s; shp->y2 /= s;
        break;
    case Shape::sqr:
        shp->x1 /= s; shp->y1 /= s;
        shp->x2 /= s; shp->y2 /= s;
        shp->x3 /= s; shp->y3 /= s;
        shp->x4 /= s; shp->y4 /= s;
        break;

    case Shape::cube:
        shp->x1 /= s; shp->y1 /= s; shp->z1 /= s;
        shp->x2 /= s; shp->y2 /= s; shp->z2 /= s;
        shp->x3 /= s; shp->y3 /= s; shp->z3 /= s;
        shp->x4 /= s; shp->y4 /= s; shp->z4 /= s;
        shp->x5 /= s; shp->y5 /= s; shp->z5 /= s;
        shp->x6 /= s; shp->y6 /= s; shp->z6 /= s;
        shp->x7 /= s; shp->y7 /= s; shp->z7 /= s;
        shp->x8 /= s; shp->y8 /= s; shp->z8 /= s;
        break;
    }

    return shp;
}

//void setType(int type);