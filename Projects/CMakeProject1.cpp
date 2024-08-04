#include <iostream>
#include <pqxx/pqxx>
#include <pqxx/connection>
#include <pqxx/transaction>
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
            "id_client INTEGER NOT NULL, "
            "number_phone VARCHAR(50) NOT NULL); "

            "CREATE TABLE IF NOT EXISTS  person_phone("
            "person_id INTEGER REFERENCES person(id), "
            "phone_id INTEGER REFERENCES phone(id), "
            "CONSTRAINT pk PRIMARY KEY(person_id, phone_id)); "
        );
        w1.commit();
    }// метод, создающий структуру БД (таблицы)
          

   int addClient(const std::string& first_name, const std::string& last_name, const std::string& e_mail) {       
       
       pqxx::work w2{ c };

        w2.exec_params("INSERT INTO person(f_name, l_name, e_mail) VALUES ($1, $2, $3)", first_name, last_name, e_mail); 

        int client_id = w2.query_value<int>("SELECT id FROM person");
        
        w2.commit();        

        return client_id;
    } //создаём клиента и возвращаем его clientId


    
   void addPhoneNumber(int client_id, const std::string& phone_number) {
       
       int phones_id = 0;

       pqxx::work w3{ c };

       w3.exec_params("INSERT INTO phone(id_client, number_phone) VALUES ($1, $2)", client_id, phone_number);

       //for (auto &[phones_id] : w3.query<int>(
           //"SELECT id FROM phone"))
       //{
          
       //}

       phones_id = w3.query_value<int>("SELECT id FROM phone LIMIT 1");

       w3.commit();


       pqxx::work w4{ c };

       w4.exec_params("INSERT INTO person_phone(person_id, phone_id) VALUES ($1, $2)", client_id, phones_id);

       w4.commit();
    }




    //void updateClient(int clientId, const std::string& firstName, const std::string& lastName, const std::string& email)

    //void removeClient(int clientId)

    //void findClient(const std::string& searchValue)


};








int main() {

    try
    {
        ClientManager manager;
        manager.initDbStruct();

        int id_client = manager.addClient("Ivan", "Ivanovskiy", "ivgrp@example.com");

        manager.addPhoneNumber(id_client, "8-800-555-35-35");
        manager.addPhoneNumber(id_client, "8-815-010-77-34");
        manager.addPhoneNumber(id_client, "8-8915-789-01-33");
        //manager.addClient("Vasiliy", "Vasiliev", "vasgrp@example.com");


        //manager.addPhoneNumber(1, "8-800-555-35-35");



    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }




    std::cout << "Hello World!\n";
    return 0;
}

