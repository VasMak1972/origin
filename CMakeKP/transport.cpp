#include <iostream>
#include <string>
#include "transport.h"

//ÒĞÀÍÑÏÎĞÒÍÎÅ ÑĞÅÄÑÒÂÎ
Transport::Transport() {
    name = "Òğàíñïîğò";
    speed = 1;
}

void Transport::print() {
    std::cout << name;
    //std::cout << speed << std::endl;
}

double Transport::race(int distance) {
    double time = distance / speed;
    return time;
}

std::string Transport::getNameTransport() {
    return name;
}