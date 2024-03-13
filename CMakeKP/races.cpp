#include <iostream>
#include <string>
#include "races.h"



//Â È Ä Û   Ã Î Í Ê È

void  Races::setRaces(std::string name, double time) {
    name_race = name;
    time_race = time;
}

std::string Races::getNameRaces() {
    return name_race;
}

double Races::getTimeRaces() {
    return time_race;
}