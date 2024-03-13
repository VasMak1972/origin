// Определяет точку входа для приложения

#include <iostream>
#include <string>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#include "transport.h"
#include "erthTransport.h"
#include "airTransport.h"
#include "types.h"
#include "races.h"


//В Ы В О Д   О С Н О В Н О Г О  И Н Ф О Р М А Ц И О Н Н О Г О   М Е Н Ю  
void print_race(Races* race, AllTypes& all, double distance, std::string str, int k) {
    std::cout << std::endl;
    std::cout << str;
    std::cout << "Расстояние: " << distance << std::endl;

    std::cout << "Зарегистрированные транспортные средства: ";
    for (int i = 1; i <= k; i++) {
        std::cout << (i == 1 ? "" : ",  ") << race[i].getNameRaces();
    }
    std::cout << std::endl;
    std::cout << std::endl;
    all.print_list();
    std::cout << std::endl;
}


//void clrscr() {
    // Function to clear the screen
    //std::cout << "\033[2J\033[1;1H";
    
//}




int main() {

    SetConsoleCP(1251);   
    SetConsoleOutputCP(1251);

    std::string name;
    double distance;
    double time;

    int type_tran = -1;
    int registr = 0;

    // П Р И В Е Т С Т В И Е
    std::cout << "Добро пожаловать в гоночный симулятор!\n";



    do {
        int type_race = 0;


        //В Ы Б О Р  В И Д А  Г О Н К И
        std::cout << "1. Гонка для наземного транспорта\n";
        std::cout << "2. Гонка для воздушного транспорта\n";
        std::cout << "3. Гонка для наземного и воздушного транспорта\n";
        std::cout << std::endl;

        std::string str;
        AllTypes all; AllTypes tmp; Races race;

        while (type_race != 1 && type_race != 2 && type_race != 3) {
            std::cout << "Выберите тип гонки: ";
            std::cin >> type_race;
            std::cout << std::endl;

            switch (type_race) {
            case 1: {str = race.str_1; EarhTypes earth; tmp = earth; break; }
            case 2: {str = race.str_2; AirTypes air; tmp = air; break; }
            case 3: {str = race.str_3; tmp = all; break; }
            default: std::cout << "Неверный тип гонки!\n";
            }
        }
        std::cout << std::endl;


        std::cout << "Укажите длину дистанции (должна быть положительна): ";
        std::cin >> distance;
        std::cout << std::endl;


        //Р Е Г И С Т Р А Ц И Я
        int n = 0;
        int k = 0;
        const int size = 10;
        int s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0;
        Races races[size];

        do {

            //clrscr();
            system("cls");

            std::cout << "Должно быть зарегистрировано хотя бы 2 транспортных средства\n";
            std::cout << std::endl;

            while (registr != 1) {
                std::cout << "1. Зарегистрировать транспорт\n";
                std::cout << "Выберите действие: ";
                std::cin >> registr;

                switch (registr) {
                case 1: break;
                default: std::cout << "Неверный ввод\n";
                }
            }

            print_race(races, all, distance, str, k);


            // Ц И К Л  В Ы Б О Р А   Т Р А Н С П О Р Т А 
            do {



                std::cout << std::endl;

                n = 0;

                std::cout << "Выберите транспорт или 0 для окончания регистрации: ";
                std::cin >> type_tran;
                std::cout << std::endl;

               // clrscr();
                system("cls");

                Transport transport;
                Transport trn;
                Camel camel; CamelFast camel_fast; Kentavr kentavr; Boots boots;
                Carpet_fly carpet; Broom broom; Eagle eagle;

                bool error = false;

                switch (type_tran) {
                case 0: n--; break;

                case 1: s1++;
                    if (s1 > 1)
                    {
                        std::cout << "Ботинки-вездеходы уже зарегистрированы!"; n--; error = true;  break;
                    }
                    if (all.boots == tmp.boots)
                    {
                        std::cout << "Ботинки-вездеходы успешно зарегистрированы!"; n++; transport = boots; trn = boots; break;
                    }
                    std::cout << "Ботинки-вездеходы неправильное транспортное средство!"; n--; error = true; break;

                case 2: s2++;
                    if (s2 > 1)
                    {
                        std::cout << "Метла уже зарегистрирована!"; n--; error = true; break;
                    }
                    if (all.broom == tmp.broom)
                    {
                        std::cout << "Метла успешно зарегистрирована!"; n++; transport = broom; trn = broom; break;
                    }
                    std::cout << "Метла неправильное транспортное средство!"; n--; error = true; break;

                case 3: s3++;
                    if (s3 > 1)
                    {
                        std::cout << "Верблюд уже зарегистрирован!"; n--; error = true; break;
                    }
                    if (all.camel == tmp.camel)
                    {
                        std::cout << "Верблюд успешно зарегистрирован!"; n++; transport = camel; trn = camel; break;
                    }
                    std::cout << "Верблюд неправильное транспортное средство!"; n--; error = true; break;

                case 4: s4++;
                    if (s4 > 1)
                    {
                        std::cout << "Кентавр уже зарегистрирован!"; n--; error = true; break;
                    }
                    if (all.kentavr == tmp.kentavr)
                    {
                        std::cout << "Кентавр успешно зарегистрирован!"; n++; transport = kentavr; trn = kentavr; break;
                    }
                    std::cout << "Кентавр неправильное транспортное средств!"; n--; error = true; break;

                case 5: s5++;
                    if (s5 > 1)
                    {
                        std::cout << "Орел уже зарегистрирован!"; n--; error = true; break;
                    }
                    if (all.eagle == tmp.eagle)
                    {
                        std::cout << "Орел успешно зарегистрирован!"; n++; transport = eagle; trn = eagle; break;
                    }
                    std::cout << "Орел неправильное транспортное средство!"; n--; error = true; break;

                case 6: s6++;
                    if (s6 > 1)
                    {
                        std::cout << "Верблюд-быстроход уже зарегистрирован!"; n--; error = true; break;
                    }
                    if (all.camel_fast == tmp.camel_fast)
                    {
                        std::cout << "Верблюд-быстроход успешно зарегистрирован"; n++; transport = camel_fast; trn = camel_fast; break;
                    }
                    std::cout << "Верблюд-быстроход неправильное транспортное средство!"; error = true; n--; break;

                case 7: s7++;
                    if (s7 > 1)
                    {
                        std::cout << "Ковер-самолет уже зарегистрированы!"; n--; error = true; break;
                    }
                    if (all.carpet == tmp.carpet)
                    {
                        std::cout << "Ковер-самолет успешно зарегистрирован!"; n++; transport = carpet; trn = carpet; break;
                    }
                    std::cout << "Ковер-самолет неправильное транспортное средство!"; n--; error = true; break;

                default: {std::cout << "Попытка зарегистрировать несуществующи0й тип транспорта!\n"; n--; }
                }
                //}


                if (!error && type_tran != 0) {

                    k++;
                    name = transport.getNameTransport();
                    time = trn.race(distance);
                    races[k].setRaces(name, time);
                }

                print_race(races, all, distance, str, k);


                // В Ы Б О Р:  С Т А Р Т / П Р О Д О Л Ж Е Н И Е   Р Е Г И С Т Р А Ц И Я

                if (type_tran == 0 && k > 1) {

                    //clrscr();
                    system("cls");

                    int start = 0;

                    std::cout << "1. Зарегистрировать транспорт?\n";
                    std::cout << "2. Начать  гонку?\n";
                    std::cout << "Выберите действие: ";
                    std::cin >> start;

                    if (start == 1) {

                        //clrscr();
                        system("cls");

                        print_race(races, all, distance, str, k);

                        type_tran = -1;
                    }
                    else { break; }
                }


                //У С Л О В И Е  П Р О Д О Л Ж Е Н И Е   Р Е Г И С Т Р А Ц И Я
                      //std::cout << "type_tran=" <<  type_tran << std::endl;
                type_tran = (type_tran == 0 ? 0 : -1);
                std::cout << std::endl;

            } while (type_tran != 0);

        } while (k < 2);

        //clrscr();
        system("cls");



        //Р Е З У Л Ь Т А Т Ы    Г О Н К И

        std::cout << "Результаты гонки: \n\n";
        //С О Р Т И Р О В К А   Р Е З У Л Ь Т А Т О В  Г О Н К И

        Races temp;

        for (int j = 1; j < k; j++) {
            for (int i = 1; i < k; i++) {

                if (races[i].getTimeRaces() > races[i + 1].getTimeRaces()) {
                    temp = races[i];
                    races[i] = races[i + 1];
                    races[i + 1] = temp;
                }
            }
        }

        //П Е Ч А Т Ь  Р Е З У Л Ь Т А Т О В  Г О Н К И
        for (int i = 1; i <= k; i++) {
            std::cout << i << ". " << races[i].getNameRaces() << ". " << "Время:  " << races[i].getTimeRaces();
            std::cout << std::endl;
        }

        //В Ы Б О Р:  В Ы Х О Д / С Т А Р Т
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "1. Провести еще одну гонку?\n";
        std::cout << "2. Выйти\n";
        std::cout << "Выберите действие: ";
        std::cin >> registr;

        //clrscr();
        system("cls");

    } while (registr == 1);


    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Ф И Н И Ш !\n";
    return 0;
}
