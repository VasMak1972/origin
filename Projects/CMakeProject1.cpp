#include <iostream>
#include <pqxx/pqxx>
#include <string>


class ClientManager {
  private:
    pqxx::connection c;
    //pqxx::work w1;
    //pqxx::work w2;


   public:
    ClientManager(): c(
        "host=localhost " //обязательно пробел
        "port=5432 " //стандартный порт psql
        "dbname=postgres " //своё имя базы
        "user=postgres " //своё имя пользователя
        "password=Parol1972") //свой пароль
    {
        std::cout << "Connection OK" << std::endl;
    } //конструктор, который настраивает соединение, может быть с параметрами

    void initDbStruct() {
        pqxx::work w1{ c };
        w1.exec("CREATE TABLE  IF NOT EXISTS "
            "person (id SERIAL PRIMARY KEY, "
            "f_name TEXT NOT NULL, "
            "l_name TEXT NOT NULL, "
            "e_mail VARCHAR(50) NOT NULL); "

            "CREATE TABLE  IF NOT EXISTS "
            "phone (id SERIAL PRIMARY KEY, "
            "number_phone VARCHAR(50) NOT NULL); "

            "CREATE TABLE IF NOT EXISTS  person_phone("
            "person_id INTEGER REFERENCES person(id), "
            "phone_id INTEGER REFERENCES phone(id), "
            "CONSTRAINT pk PRIMARY KEY(person_id, phone_id)); "
        );
        w1.commit();
    }// Метод, создающий структуру БД (таблицы)
          

    void addClient(const std::string& first_Name, const std::string& last_Name, const std::string& e_mail) {   
       
       
       pqxx::work w2{ c };
         
        w2.exec(//"EXEC SQL BEGIN DECLARE SECTION; "
                "DECLARE varchar first_Name ; "
                "DECLARE last_Name varchar; "
                "DECLARE e_mail varchar; "
                //"EXEC SQL END DECLARE SECTION; "
                "INSERT INTO person(f_name, l_name, e_mail) VALUES (:first_Name, :last_Name, :e_mail);"
        );
        w2.commit();
    } //создаём клиента и возвращаем его clientId


    //void addPhoneNumber(int clientId, const std::string& phoneNumber)

    //void updateClient(int clientId, const std::string& firstName, const std::string& lastName, const std::string& email)

    //void removeClient(int clientId)

    //void findClient(const std::string& searchValue)


};








int main() {

    try
    {
        ClientManager manager;
        manager.initDbStruct();
        manager.addClient("Ivan", "Ivanov", "tugrp@example.com");
        //manager.addPhoneNumber(1, "8-800-555-35-35");



    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }




    std::cout << "Hello World!\n";
    return 0;
}

