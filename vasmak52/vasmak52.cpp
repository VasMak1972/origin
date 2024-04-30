// vasmak52.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <algorithm>


template <typename T>
void print_container(const T& elemts) {
    for (const auto& elemt : elemts) {
        std::cout << elemt << ", ";
    }
    std::cout << std::endl;
}


int main() {

    //std::set<std::string> test_set = { "one", "two", "three", "four" };
    //print_container(test_set); 

    std::list<std::string> test_list = { "one", "two", "three", "four" };
    print_container(test_list);

    //std::vector<std::string> test_vector = { "one", "two", "three", "four" };
    //print_container(test_vector);


    std::cout << "\n\nHello World!\n";
    return 0;
}