#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <iterator>
#include <chrono>
#include <thread>
#include <time.h>
#include <math.h>
#include <tuple>


void sum(std::vector<int>& a, std::vector<int>& b, std::vector<int>& c, int start, int end)
{
    for (int i = start; i < c.size(); i = i + end) {
        std::this_thread::sleep_for(std::chrono::nanoseconds(1));
        c[i] = a[i] + b[i];
        //std::cout << "start = " << start << std::endl;
        //std::cout << c[i] << "  ";
        //std::cout << std::endl;
    }
}


std::vector<int> rand_vec(int lngth)
{
    srand(time(0));
    std::vector<int> rand_arr;
    for (int i = 0; i < lngth; ++i) {
        rand_arr.push_back(rand() % 89 + 10);
    }
    return rand_arr;
}





int main() {

    const int cols = 5;
    std::tuple<int, int, double, double, double, double, double>  obj[cols];

    unsigned int N = std::thread::hardware_concurrency();
    std::cout << "Number of threads: " << N << std::endl;
    std::cout << std::endl;

      
    std::vector<int> v1;
    std::vector<int> v2;

// *************** Разделение на потоки ****************************************

    double times[5]{ 0 };

    int calctr = 0;
    int col = 0;
    for (int i = 1; i <= 16; i = 2 * i) {

        std::cout << "Processing " << calctr+1 << std::endl;
        std::cout << "thread = " << i << std::endl;
        std::vector<std::thread> tr(i);        

        int rows = 0;
        for (int n = 1000; n <= 100000; n = 10 * n) {
           
            std::vector<int> v3(n);
            v1 = rand_vec(n);
            std::this_thread::sleep_for(std::chrono::seconds(2));
            v2 = rand_vec(n);

            //for (int i = 0; i < v1.size(); i++) {
                //std::cout << v1[i] << "\t";
            //}
            //std::cout << std::endl;

            //for (int i = 0; i < v2.size(); i++) {
                //std::cout << v2[i] << "\t";
            //}
            //std::cout << std::endl;

            auto start = std::chrono::high_resolution_clock::now();

            for (int j = 0; j < i; j++) {
                tr[j] = std::thread(sum, std::ref(v1), std::ref(v2), std::ref(v3), j, i);
            }
            for (int j = 0; j < i; j++) {
                tr[j].join();
            }

            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> time = end - start;
            times[rows] = time.count();

            std::cout << "n = " << n << std::endl;
            std::cout << "time" << rows + 1 << " = " << times[rows] << std::endl;

            //for (int k = 0; k < v3.size(); k++) {
                //std::cout << v3[k] << "\t";
            //}             

            rows++;
            calctr++;           
        }


        // ***************** Сохранение данных *****************************

        if (col < log10(1000)) {

        std::get<0>(obj[col]) = 1000 * pow(10, col);
        }
        std::get<1>(obj[col]) = i;
        std::get<2>(obj[col]) = times[0];
        std::get<3>(obj[col]) = times[1];
        std::get<4>(obj[col]) = times[2];
        //std::get<5>(obj[col]) = times[3];
        //std::get<6>(obj[col]) = times[4];

        col++;
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;

    // ***************** Вывод *****************************

    
    for (int i = 0; i < log10(1000); i++) {
        std::cout << " \t";
        std::cout << std::get<0>(obj[i]) << " \t";
        //std::cout << " \t";
    }
    std::cout << std::endl;

    for (int i = 0; i < cols; i++) {

        std::cout << std::get<1>(obj[i]) << " \t";
        std::cout << std::get<2>(obj[i]) << " \t";
        std::cout << std::get<3>(obj[i]) << " \t";
        std::cout << std::get<4>(obj[i]) << " \t";
        //std::cout << std::get<5>(obj[i]) << " \t";
        //std::cout << std::get<6>(obj[i]) << " \t";
        std::cout << std::endl;
    }





    std::cout << std::endl;
    std::cout << "\n\nHello World!\n";
    return 0;
}
