#pragma once
#include <iostream>
#include <string>

//В И Д Ы   Г О Н К И
class Races {
protected:
    std::string name_race;
    double time_race;

public:
    std::string str_1;
    std::string str_2;
    std::string str_3;

    Races() {
        str_1 = "Гонка для наземного транспорта. ";
        str_2 = "Гонка для воздушного транспорта. ";
        str_3 = "Гонка для наземного и воздушного транспорта. ";
    }



    void setRaces(std::string name, double time);

    std::string getNameRaces();

    double getTimeRaces();
};
