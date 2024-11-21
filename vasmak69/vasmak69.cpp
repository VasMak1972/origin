// vasmak69.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы

// Сортировка массива с помощью алгоритма сортировки выбором
#include <iostream>       // std::cout
#include <functional>     // std::ref
#include <thread>         // std::thread
#include <future>         // std::promise, std::future
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

// Функции для поиска минимального элемента массива
static int scan_min(int* arr, std::future<int>& ftr) {

    int size = ftr.get();
    int min = 0;
    for (int j = 1; j < size; j++) {
        if (arr[j] < arr[min]) {
            min = j;
        }
    }
    return min;
}






//main функция
int main() {
    // Массив для сортировки    
    int array[] = { 99, 5, 2, 11, 4, 43, 0, 9, 84, 7, 6, -2, 23, 67, 4};
    int size = sizeof(array) / sizeof(array[0]);

    // Вывод массива
    std::cout << "Array before: ";
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;


    // Сортировка массива    
    for (int i = 0; i < size - 1; i++) {

        std::promise<int> prms;
        std::future<int> ftr = prms.get_future();
        auto min = std::async(scan_min, array + i, std::ref(ftr));

        // Нахождение индекса минимального элемента в массиве    
        prms.set_value(size - i);
        int indx = min.get() + i;

        // Обмен местами минимального элемента с текущим элементом
        int temp = array[i];
        array[i] = array[indx];
        array[indx] = temp;
    }


    // Вывод отсортированного массива
    std::cout << "Array  after: ";
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;


    std::cout << std::endl;
    std::cout << "\n\nHello, World!" << std::endl;
    return 0;
}