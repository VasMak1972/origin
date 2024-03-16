#include <iostream>
#include <string>
#include "erthTransport.h"

//НАЗЕМНЫЙ ТРАНСПОРТ

    void ErthTransport::print() {
        std::cout << name << std::endl;
        std::cout << std::endl;
    }

    double ErthTransport::race(double distance) {
        double time = distance / speed;
        double  n = time / time_trvel;
        int k = n;

        if (n <= 1) {}
        if (n > 1 && n <= 2) {
            time = time + time_out_1;
        }
        else if (n > 2 && n > k) {
            time = time + time_out_1 + (k - 1) * time_out_2;
        }
        else if (n > 2 && n == k) {
            time = time + time_out_1 + (k - 2) * time_out_2;
        }
        return time;
    }



//Ботинки-вездеходы


//Верблюд


//Кентавр

    double Kentavr::race(double distance) {

        double time = distance / speed;
        double  n = time / time_trvel;
        int k = n;

        if (n <= 1) {}
        if (n > k) {
            time = time + k * time_out_1;
        }
        else if (n == k) {
            time = time + (k - 1) * time_out_1;
        }
        std::cout << time << std::endl;
        return time;
    }



//Верблюд - быстроход

  
    double CamelFast::race(double distance) {
        double time = distance / speed;
        double  n = time / time_trvel;
        int k = n;
        if (n <= 1) {}
        if (n > 1 && n <= 2) {
            time = time + time_out_1;
        }
        else if (n > 2 && n <= 3) {
            time = time + time_out_1 + time_out_2;
        }
        else if (n > 3 && n > k) {
            time = time + time_out_1 + time_out_2 + (k - 2) * time_out_3;
        }
        else if (n > 3 && n == k) {
            time = time + time_out_1 + time_out_2 + (k - 3) * time_out_3;
        }
        return time;
    }

