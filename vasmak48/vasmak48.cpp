#include <iostream>
#include <vector>
#include <algorithm> 


class functor {
    int sum;
    int count;

  public:
    functor() { sum = 0; count = 0; }
    /*
    void operator()(int a) {
      if (a % 3 == 0) {
        sum += a;
        count++;
      }
    }
    */

    int operator()(int a) {
        if (a % 3 == 0) {
            sum += a;
            count++;
        }
        return count;
        return sum;
    }
    

    int get_sum() {
        return sum;
    }
    int get_count() {
        return count;
    }
};


int main() {

    functor f;
    std::vector<int> vec = { 4, 1, 3, 6, 25, 54 };

    functor s = for_each(vec.begin(), vec.end(), f);

    std::cout << "sum =" << "\t" << s.get_sum() << std::endl;
    std::cout << "count =" << "\t" << s.get_count() << std::endl;


    std::cout << "\n\n\nHello World!\n";
    return 0;
}