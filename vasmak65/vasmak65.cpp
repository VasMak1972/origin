// vasmak65.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <atomic>
#include <chrono>
#include <iostream>
#include <thread>

std::atomic<int> sum(0); // Atomic integer 
std::atomic_flag flag = ATOMIC_FLAG_INIT;


void foo1(int id, int N)
{
    while (sum <= N) {
        while (flag.test_and_set(std::memory_order_acquire)) {}
        sum.fetch_add(1);
        //std::cout << "sum = " <<sum << std::endl;
        std::cout << "Queue+..." << sum << std::endl;
        flag.clear(std::memory_order_release); // Release lock 
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void foo2(int id)
{
    while (sum > 0) {
        while (flag.test_and_set(std::memory_order_acquire)) {}
        //std::cout << "sum = " << sum << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        sum.fetch_sub(1);
        std::cout << "Queue-..." << sum << std::endl;
        flag.clear(std::memory_order_release); // Release lock
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
}





int main() {

    int N = 10;
    //int queue = 0;

    std::cout << "Start first client...\n";
    std::thread client(foo1, 1, N);

    std::cout << "Start work helper...\n";
    std::thread helper(foo2, 2);

    //std::cout << "Starting operation...\n";

    client.join();
    helper.join();

    std::cout << std::endl;
    std::cout << "End queue!\n";


    std::cout << "Hello World!\n";
    return 0;
}


