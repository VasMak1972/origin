#include <iostream>
#include <string>
#include "airTransport.h"



//ÂÎÇÄÓØÍÛÉ ÒÐÀÍÑÏÎÐÒ

void AirTransport::print() {
    std::cout << name << std::endl;
    std::cout << std::endl;
}

double AirTransport::race(double distance) {
    double time = (factor * distance) / speed;
    return time;
}


//Î נ ו כ


//Êמגונ-סאלמכוע

double Carpet_fly::race(double distance) {

    if (distance >= 1000 && distance < 5000) { factor = 0.97; }
    else if (distance >= 5000 && distance < 10000) { factor = 0.9; }
    else if (distance >= 10000) { factor = 0.95; }

    double time = (factor * distance) / speed;
    return time;
}


//Ì ו ע כ א

double Broom::race(double distance) {
    int k = distance / 1000;
    factor = (1 - 0.01 * k);
    double time = (factor * distance) / speed;
    return time;
}
