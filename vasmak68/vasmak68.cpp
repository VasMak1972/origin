// vasmak68.cpp : Окончательный вариант

#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <stdio.h>
#include <Windows.h>


static void SetColor(int text, int bg) {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, ((bg << 2) | text));
}

class Data
{
private:
    std::vector<int> value_{ 0 };
    //std::vector<int> data_;

public:

    Data() = default;
    Data(std::vector<int> data) : data_{ data } {}
    std::vector<int> data_;
    std::mutex mutex_;    

    std::vector<int> getValue() const
    {
        return data_;
    }

    void setValue(std::vector<int> value)
    {
        data_ = value;
    }
};


static void swap_with_lock(Data& d1, Data& d2)
{
   
    //SetColor(6, 3);    
    std::lock(d1.mutex_, d2.mutex_);
    std::lock_guard<std::mutex> lg1(d1.mutex_, std::adopt_lock);
    SetColor(6, 3);

    std::lock_guard<std::mutex> lg2(d2.mutex_, std::adopt_lock);
  
    //d1.Data::data_.swap(d2.Data::data_);
    std::vector<int> tmp = d1.getValue();
    d1.setValue(d2.getValue());
    d2.setValue(tmp);

    std::cout << std::endl << "ThreadId: " << std::this_thread::get_id() << ". after: " __FUNCTION__ << std::endl;   
    std::cout << "data_1 = ";
    for (int& elem : d1.Data::data_) {
        std::cout << elem << ", ";        
    }    
    std::cout << "\n";

    std::cout << "data_2 = ";
    for (int& elem : d2.Data::data_) {
        std::cout << elem << ", ";
    }    
    std::cout << "\n";
    SetColor(3, 3);
}



static void swap_with_scopedlock(Data& d1, Data& d2)
{
    //SetColor(4, 3);
    std::scoped_lock lock(d1.mutex_, d2.mutex_);
    SetColor(4, 3);
    //swap
    std::vector<int> tmp = d1.getValue();
    d1.setValue(d2.getValue());
    d2.setValue(tmp);

    //print
    std::cout << std::endl << "ThreadId: " << std::this_thread::get_id() << ". after: " __FUNCTION__ << std::endl;
    std::cout << "data_1 = ";
    for (int& elem : d1.Data::data_) {
        std::cout << elem << ", ";
    }
    std::cout << "\n";

    std::cout << "data_2 = ";
    for (int& elem : d2.Data::data_) {
        std::cout << elem << ", ";
    }
    std::cout << "\n";
    SetColor(3, 3);
}


static void swap_with_uniquelock(Data& d1, Data& d2)
{
   //SetColor(1, 3);
    std::unique_lock<std::mutex> lk1(d1.mutex_, std::defer_lock);
    std::unique_lock<std::mutex> lk2(d2.mutex_, std::defer_lock);    
    std::lock(lk1, lk2);

    SetColor(5, 3);
    //swap
    std::vector<int> tmp = d1.getValue();
    d1.setValue(d2.getValue());
    d2.setValue(tmp);

    //print
    std::cout << std::endl << "ThreadId: " << std::this_thread::get_id() << ". after: " __FUNCTION__ << std::endl;
    std::cout << "data_1 = ";
    for (int& elem : d1.Data::data_) {
        std::cout << elem << ", ";
    }
    std::cout << "\n";

    std::cout << "data_2 = ";
    for (int& elem : d2.Data::data_) {
        std::cout << elem << ", ";
    }
    std::cout << "\n";
    SetColor(3, 3);
}


int main()
{
    std::cout << "ID main thread: " << std::this_thread::get_id() << "\n";  

    std::vector<int> data1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    std::vector<int> data2{ 11, 12, 13, 14, 15, 16, 17, 18, 19 };

    Data d1(data1), d2(data2);

    std::cout << "\nBefore:\n"; 
    std::cout << "data_1 = ";
    for (int& elem : d1.Data::data_) {
        std::cout << elem << ", ";
    }
    std::cout << "\n";

    std::cout << "data_2 = ";
    for (int& elem : d2.Data::data_) {
        std::cout << elem << ", ";
    }
    std::cout << "\n";


    std::thread thread1(swap_with_lock, std::ref(d1), std::ref(d2));
    std::thread thread2(swap_with_scopedlock, std::ref(d1), std::ref(d2));
    std::thread thread3(swap_with_uniquelock, std::ref(d1), std::ref(d2));

    thread1.join();
    thread2.join();
    thread3.join();

    SetColor(3, 3);
    std::cout << "\n\nHello World!\n";
    return 0;
}