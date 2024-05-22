#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


template <typename T>
void move_vectors(T&& _one, T&& _two) {
    std::cout << "move_vectors" << std::endl;
    _two = std::move(T(_one));
}


int main() {

    //std::vector<std::string> one = { "test_string_1", "test_string_2" };
    //std::vector<std::string> two;

    std::vector<int> one = {1, 2, 3, 4, 5, 6, 7};
    std::vector<int> two = {8, 9, 10, 11, 12, 13}; 


    std::cout << "Elemts one: " << std::endl;
    for (const auto& elemt : one) {
        std::cout << elemt << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Elemts two: " << std::endl;
    for (const auto& elemt : two) {
        std::cout << elemt << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    move_vectors(one, two);
    //move_vectors(two, one);
    std::cout << std::endl;

    std::cout << "Elemts two: " << std::endl;
    for (const auto& elemt : two) {
        std::cout << elemt << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Elemts one: " << std::endl;
    for (const auto& elemt : one) {
        std::cout << elemt << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;


    std::cout << "\n\n\nHello World!\n";
    return 0;
}
