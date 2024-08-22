#include <iostream>
#include <chrono>
#include <thread>


static void foo(int& i, int N)
{
    // simulate expensive operation
    std::cout << "foo" << std::endl;
    //std::cout << "i = " << i << std::endl;
    std::cout << "N = " << N << std::endl;

    while (i <= N) {
        
        //std::cout << "i = " << i << std::endl;
        std::cout << "Queue+..." << i << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        i++;
    }
}

static void work(int& j)
{
    // simulate expensive operation 
    std::cout << "work" << std::endl;
    while (j > 0) {
        //std::cout << "j = " << j << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        j--;
        std::cout << "Queue-..." << j << std::endl;
    }
}



int main()
{

    int N = 5;
    int queue = 1;

    std::cout << "Start first client...\n";
    std::thread client(foo, std::ref(queue), N);    

    std::cout << "Start work helper...\n";
    std::thread helper(work, std::ref(queue));

    //std::cout << "Starting operation...\n";

    client.join();
    helper.join();

    std::cout << std::endl;
    std::cout << "End queue!\n";

    std::cout << "Hello World!\n";
    return 0;
}

