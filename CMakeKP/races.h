#pragma once
#include <iostream>
#include <string>

//� � � �   � � � � �
class Races {
protected:
    std::string name_race;
    double time_race;

public:
    std::string str_1;
    std::string str_2;
    std::string str_3;

    Races() {
        str_1 = "����� ��� ��������� ����������. ";
        str_2 = "����� ��� ���������� ����������. ";
        str_3 = "����� ��� ��������� � ���������� ����������. ";
    }



    void setRaces(std::string name, double time);

    std::string getNameRaces();

    double getTimeRaces();
};
