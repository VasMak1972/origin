// vasmak51.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <Windows.h>

int main() {

    SetConsoleCP(1251); 
    SetConsoleOutputCP(1251);

    std::string str;
    std::string num;

    std::cout << "Введите через пробел " << std::endl;
    std::cout << "ряд положительных чисел: ";
    std::getline(std::cin, str);
    std::cout << std::endl;

    int size = str.length();
    std::vector<int> vec;

    for (int i = 0; i < size; i++) {

        if (str[i] != ' ' || str[i + 1] == ' ') {
            num += str[i];
        }
        else {
            int elmt = stoi(num);
            vec.push_back(elmt);
            num = " ";
        }
    }
    if (str[size - 1] != ' ') {
        vec.push_back(stoi(num));
    }

    std::cout << "Ваш числовой ряд: ";
    for (auto v : vec) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    std::sort(vec.begin(), vec.end());

    auto last = std::unique(vec.begin(), vec.end());

    vec.erase(last, vec.end());

    std::cout << "Уникальный числовой ряд: ";
    for (auto v : vec) {
        std::cout << v << " ";
    }


    std::cout << "\n\n\nHello World!\n";
    return 0;
}