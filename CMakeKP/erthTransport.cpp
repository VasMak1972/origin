#include <iostream>
#include <string>
#include "erthTransport.h"

//НАЗЕМНЫЙ ТРАНСПОРТ

void ErthTransport::print() {
    std::cout << name << std::endl;
    std::cout << std::endl;
}

double ErthTransport::race(int distance) {
    double time = distance / speed;
    int n = time / time_trvel;
    if (n >= 1) {
        time = time + n * time_out_1;
    }
    else if (static_cast<int>(time) % time_trvel == 0) {
        time = time - time_out_1;
    }
    return time;
}



//Кентавр


//Верблюд

double Camel::race(int distance) {
    double time = distance / speed;
    int n = time / time_trvel;

    if (n == 1) {
        time = time + time_out_1;
    }
    else if (n >= 2) {

        if (static_cast<int>(time) % time_trvel != 0) {

            std::cout << static_cast<int>(time) % time_trvel << std::endl;

            time = time + time_out_1 + (n - 1) * time_out_2;
        }
        else { time = time + time_out_1 + (n - 2) * time_out_2; }
    }
    return time;
}


//Ботинки-вездеходы

double Boots::race(int distance) {
    double time = distance / speed;
    int n = time / time_trvel;

    if (n == 1) {
        time = time + time_out_1;
    }
    else if (n >= 2) {

        if (static_cast<int>(time) % time_trvel != 0) {

            std::cout << static_cast<int>(time) % time_trvel << std::endl;

            time = time + time_out_1 + (n - 1) * time_out_2;
        }
        else { time = time + time_out_1 + (n - 2) * time_out_2; }
    }
    return time;
}


//Верблюд - быстроход

double CamelFast::race(int distance) {
    double time = distance / speed;
    int n = time / time_trvel;

    if (n == 1) { time = time + time_out_1; }
    else if (n >= 2 && n < 3) { time = time + time_out_1 + time_out_2; }
    else if (n >= 3) {
        time = time + time_out_1 + time_out_2 + (n - 2) * time_out_3;
    }
    else if (static_cast<int>(time) % time_trvel == 0) {
        time = time - time_out_3;
    }

    return time;
}
