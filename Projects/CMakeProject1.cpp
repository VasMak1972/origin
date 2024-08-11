#include <iostream>
#include <sstream>
#include <pqxx/pqxx>
#include <pqxx/connection>
#include <pqxx/transaction>
#include <stdexcept>
#include <tuple>
#include <string>
#include <Windows.h>
#pragma execution_character_set("utf-8")


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
        std::cout << std::endl;
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
            "id_client INTEGER NOT NULL, "
            "number_phone VARCHAR(50) NOT NULL); "

            //"CREATE TABLE IF NOT EXISTS  person_phone("
            //"person_id INTEGER REFERENCES person(id) ON DELETE CASCADE, "
            //"phone_id INTEGER REFERENCES phone(id) ON DELETE CASCADE, "
            //"CONSTRAINT pk PRIMARY KEY(person_id, phone_id)); "


            "CREATE TABLE IF NOT EXISTS  person_phone("
            "person_id INTEGER NOT NULL, "
            "phone_id INTEGER NOT NULL, "
            "FOREIGN KEY(person_id ) REFERENCES person(id) ON DELETE CASCADE ON UPDATE CASCADE, "
            "FOREIGN KEY(phone_id) REFERENCES phone(id) ON DELETE CASCADE ON UPDATE CASCADE);"             
        );

        w1.commit();
    }// метод, создающий структуру БД (таблицы)
          

   int addClient(const std::string& first_name, const std::string& last_name, const std::string& e_mail) { 

       int client_id = 0;

       pqxx::work w2{ c };

        w2.exec_params("INSERT INTO person(f_name, l_name, e_mail) VALUES ($1, $2, $3)", first_name, last_name, e_mail); 

        //int client_id = w2.query_value<int>("SELECT id FROM person");

        auto clients_id = w2.query<int>("SELECT id  FROM person ");

        for (auto& [id] : clients_id)            
        {
            //std::cout << "id = " << id << std::endl;
            client_id = id;
        }
        
        w2.commit();        

        return client_id;
    } //создаём клиента и возвращаем его clientId


    
   void addPhoneNumber(int client_id, const std::string& phone_number) {
       
       int phone_id;

       pqxx::work w3{ c };       

       w3.exec_params("INSERT INTO phone(id_client, number_phone) VALUES ($1, $2)", client_id, phone_number);
       
       auto phones_id = w3.query<int>("SELECT id  FROM phone ");

       for (auto &[id] : phones_id)           
       {
           //std::cout << "id = "<< id << std::endl;
           phone_id = id;
       }
       w3.commit();
      

       pqxx::work w4{ c };       

       w4.exec_params("INSERT INTO person_phone(person_id, phone_id) VALUES ($1, $2)", client_id, phone_id);

       w4.commit();
    }


   void updateClient(int clientId, const std::string& firstName, const std::string& lastName, const std::string& email) {
   
       pqxx::work w5{ c };        

       w5.exec_params("UPDATE person SET f_name=$1, l_name=$2, e_mail=$3 WHERE id=$4", firstName, lastName, email, clientId);

       w5.commit();   
   
   }

   void removeClient(int clientId) {

       pqxx::work w6{ c };      

       w6.exec_params("DELETE FROM person WHERE id=$1", clientId);
       
       w6.commit();
   }

   void removePhone(const std::string& phone_number) {       

       pqxx::work w8{ c };       

       w8.exec_params("DELETE FROM phone WHERE number_phone=$1", phone_number);

       w8.commit();
   }
       
     
   void findClient(const std::string& searchValue) {

       pqxx::work t{ c };

       pqxx::result r = t.exec_params("SELECT * FROM person  WHERE e_mail=$1", searchValue);

       //std::cout << "The you wanted is: " << r << std::endl;

       t.commit();

       for (pqxx::result::const_iterator it = r.begin(); it != r.end(); ++it)
       {
           std::cout <<"The you wanted is: " << it[0].c_str()<<". "<< it[1].c_str() <<" "<< it[2].c_str();

           std::cout << std::endl;           
       }

       //pqxx::work q{ c };   

       //std::string author = q.query_value<std::string>("SELECT f_name FROM person WHERE id=1");

       //std::cout << "The author you wanted is: " << author << std::endl;
   }


};



int main() {

    //setlocale(LC_ALL, "Russian");
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    try
    {
       //

     ClientManager manager;
     manager.initDbStruct();

       //int id_client = 4;

       int id_client_1 = manager.addClient("Ivan", "Ivanovskiy", "ivgrp@example.com");
       int id_client_2 = manager.addClient("Petr", "Perviy", "ptgrp@example.com");
       int id_client_3 = manager.addClient("Slava", "Komarov", "kom@example.com");
       int id_client_4 = manager.addClient("Vasiliy", "Vasiliev", "vas@ya.com");

       manager.addPhoneNumber(id_client_1, "8-800-555-35-35");
       manager.addPhoneNumber(id_client_1, "8-815-010-77-34");
       manager.addPhoneNumber(id_client_2, "8-804-810-23-04");
       manager.addPhoneNumber(id_client_3, "8-810-110-17-91");
       manager.addPhoneNumber(id_client_3, "8-980-111-56-71");
       manager.addPhoneNumber(id_client_4, "8-904-723-91-12");
       manager.addPhoneNumber(id_client_4, "8-915-711-71-39");
       manager.addPhoneNumber(id_client_4, "8-895-888-31-13");

       //manager.updateClient(id_client, "Sidor", "Sidorov", "sidgrp@ya.com");       
       
       //manager.removeClient(id_client);
              
       //manager.removePhone("8-804-810-23-04");

       //manager.findClient("sidgrp@ya.com");


    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "Hello World!\n";
    return 0;
}

