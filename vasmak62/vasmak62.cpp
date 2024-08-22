#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <iterator>
#include <chrono>
#include <thread>
#include <time.h>
#include <tuple>


void sum(std::vector<int>& a, std::vector<int>& b, std::vector<int>& c, int start, int end)
{
    for (int i = start; i < c.size(); i = i + end) {
        std::this_thread::sleep_for(std::chrono::milliseconds(5));
        c[i] = a[i] + b[i];
        //std::cout << "start = " << start << std::endl;
        //std::cout << c[i] << "  ";
        //std::cout << std::endl;
    }
}

//void sum2(std::vector<int>& a, std::vector<int>& b, std::vector<int>& c, int start, int end)
//{
    //for (int i = start; i < c.size(); i = i + end) {
       // std::this_thread::sleep_for(std::chrono::milliseconds(10));
        //c[i] = a[i] + b[i];
        //std::cout << "sum2 = " << c[i] << "  ";
        //std::cout << std::endl;
    //}
//}



//void func(std::vector<int>& v) {
//
   //srand(time(0));
   // for (int i = 0; i < v.size(); i++) {
   //     v[i] = rand() % 89 + 10;
   // }
//}

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

    const int rows = 3;
    int cols = 0;

    std::tuple<int, double, double, double>obj[rows];

    unsigned int N = std::thread::hardware_concurrency();
    std::cout << "Number of threads: " << N << std::endl;
    std::cout << std::endl;


    int exp = 10;
    int n = 10;
    while (n <= 1000) {

        //int n = 5 * exp;  
        std::vector<int> v1(n);
        std::vector<int> v2(n);
        std::vector<int> v3(n);

        v1 = rand_vec(n);
        std::this_thread::sleep_for(std::chrono::seconds(2));
        v2 = rand_vec(n);

        for (int i = 0; i < v1.size(); i++) {
            std::cout << v1[i] << "\t";
        }
        std::cout << std::endl;

        for (int i = 0; i < v2.size(); i++) {
            std::cout << v2[i] << "\t";
        }
        std::cout << std::endl;
        std::cout << std::endl;


        // ***************** Первый блок *****************************

        auto start1 = std::chrono::high_resolution_clock::now();

        std::thread t(sum, std::ref(v1), std::ref(v2), std::ref(v3), 0, 1);

        auto end1 = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> time1 = end1 - start1;

        t.join();
        std::cout << std::endl;
        std::cout << "time1 = " << 1000 * time1.count() << std::endl;

        //sum(v1, v2, v3, 0, v1.size());  
        for (int i = 0; i < v3.size(); i++) {
            std::cout << v3[i] << "\t";
        }
        std::cout << std::endl;
        std::cout << std::endl;



        // ***************** Второй блок *****************************

        auto start2 = std::chrono::high_resolution_clock::now();

        std::thread t1(sum, std::ref(v1), std::ref(v2), std::ref(v3), 0, 2);
        std::thread t2(sum, std::ref(v1), std::ref(v2), std::ref(v3), 1, 2);

        auto end2 = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> time2 = end2 - start2;

        t1.join();
        t2.join();
        std::cout << std::endl;
        std::cout << "time2 = " << 1000 * time2.count() << std::endl;

        for (int i = 0; i < v3.size(); i++) {
            std::cout << v3[i] << "\t";
        }
        std::cout << std::endl;



        // ***************** Третий блок *****************************

        auto start4 = std::chrono::high_resolution_clock::now();

        std::thread tr1(sum, std::ref(v1), std::ref(v2), std::ref(v3), 0, 4);
        std::thread tr2(sum, std::ref(v1), std::ref(v2), std::ref(v3), 1, 4);
        std::thread tr3(sum, std::ref(v1), std::ref(v2), std::ref(v3), 2, 4);
        std::thread tr4(sum, std::ref(v1), std::ref(v2), std::ref(v3), 3, 4);

        auto end4 = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> time4 = end4 - start4;

        tr1.join();
        tr2.join();
        tr3.join();
        tr4.join();

        std::cout << std::endl;
        std::cout << "time4 = " << 1000 * time4.count() << std::endl;

        for (int i = 0; i < v3.size(); i++) {
            std::cout << v3[i] << "\t";
        }
        std::cout << std::endl;
        std::cout << std::endl;

        std::get<0>(obj[cols]) = n;
        std::get<1>(obj[cols]) = time1.count();
        std::get<2>(obj[cols]) = time2.count();
        std::get<3>(obj[cols]) = time4.count();

        n = n * exp;
        cols++;
    }

    // ***************** Вывод *****************************


    for (int i = 0; i < cols; i++) {
        std::cout << std::get<0>(obj[i]) << "\t";
        std::cout << std::get<1>(obj[i]) * 1000 << "\t";
        std::cout << std::get<2>(obj[i]) * 1000 << "\t";
        std::cout << std::get<3>(obj[i]) * 1000 << "\t";
        std::cout << std::endl;
    }






    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "\n\nHello World!\n";

    return 0;
}