#include <pqxx/pqxx>
#include <iostream>
#include <string>
#include <sstream>

class Clients {
private:
    //pqxx::connection conn;
    std::string person;
    std::string telephone;

protected:

    std::string name;
    std::string f_name;
    std::string e_mail;
    std::string phone;

public:

    Clients() {
        std::string name = "Name";
        std::string f_name = "FirstName";
        std::string e_mail = "e.mail";
        std::string phone = "0000000000000";
    }

    Clients(std::string name, std::string f_name, std::string e_mailhone) : Clients() {}

    void createDate(pqxx::connection& c) {

        pqxx::work t1{ c };
        t1.exec("CREATE TABLE  IF NOT EXISTS "
            "person (id SERIAL PRIMARY KEY, "
            "name TEXT NOT NULL, "
            "f_name TEXT NOT NULL, "
            "e_mail VARCHAR(50) NOT NULL); "

            "CREATE TABLE  IF NOT EXISTS "
            "phone (id SERIAL PRIMARY KEY, "
            "number_phone VARCHAR(50) NOT NULL); "

            "CREATE TABLE IF NOT EXISTS  person_phone("
            "person_id INTEGER REFERENCES person(id), "
            "phone_id INTEGER REFERENCES phone(id), "
            "CONSTRAINT pk PRIMARY KEY(person_id, phone_id)); "

        );

        t1.commit();
    }

    void addPerson(pqxx::connection& c) const noexcept {


        pqxx::work t2{ c };
        t2.exec(" INSERT INTO person(name, f_name, e_mail) VALUES ('Vasiliy', 'Vasiliev', 'vasgrp@example.com');"
        );

        t2.commit();
    }









};



int main() {

    Clients client;
    Clients client1("Petr", "Petrov", "tugrp@example.com");
    Clients client2("Sidor", "Sidorov", "tugrp@example.com");
    Clients client3("Vasiliy", "Vasiliev", "tugrp@example.com");




    try
    {
        pqxx::connection c(
            "host=localhost "
            "port=5432 "
            "dbname=postgres "
            "user=postgres "
            "password=Parol1972");

        std::cout << "Hello!" << std::endl;

        client.createDate(c);
        client.addPerson(c);




        //pqxx::work tx{ c };

         //for (auto [nickname, jenre] : tx.query<std::string, std::string>(
             //"SELECT nickname, jenre FROM autor"))
         //{
             //std::cout << nickname << " is works by: " << jenre << ".\n";
         //} 


    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }




    std::cout << "\n\n\nHello World!\n";
    return 0;
}


