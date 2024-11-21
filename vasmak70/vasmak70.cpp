// vasmak70.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>       // std::cout
#include <functional>     // std::ref
#include <thread>         // std::thread
#include <future>         // std::promise, std::future
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <chrono>
#include <cmath> // Add this line to include the cmath 



static void exp_vec(int& multipl_vec)
{
    multipl_vec = pow(multipl_vec, 2);
}

template <typename Iterator, typename T>
void for_each_async_recursive(Iterator begin, Iterator end, T init, T& recurs) {
    recurs++;   
    auto size = std::distance(begin, end);    

    if (init >= size) {
        std::for_each(begin, end, exp_vec);
    }
    else {
        auto mid = begin;
        std::advance(mid, size / 2);
        auto ftr = std::async(for_each_async_recursive<Iterator, T>, begin, mid, init, std::ref(recurs));
        for_each_async_recursive<Iterator, T>(mid, end, init, std::ref(recurs));
        ftr.get();
    }
}

int main()
{
    int num = 5;
    int num_recrs = 0;
    std::vector<int> vec = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };

    std::cout << "Before: " << std::endl;
    for (int i : vec)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;   

    for_each_async_recursive<std::vector<int>::iterator, int>(vec.begin(), vec.end(), num, std::ref(num_recrs));       

    std::cout << "\nAfter: ";
    std::cout << std::endl;
    std::cout << "num_recrs = " << num_recrs << std::endl;    
    for (int i : vec)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    std::cout << "\n\nHello! World!" << std::endl;
    return 0;
}













