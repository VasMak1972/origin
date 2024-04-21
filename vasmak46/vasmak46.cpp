#include <iostream>
#include <vector>

//Общая версия
template <typename T>
T pow_two(const T& x) {
    T y = x * x;
    return y;
}
//Перегрузка для векторов
template <typename T>
const std::vector<T> pow_two(const std::vector<T>& v1) {
    std::vector<T> v2;
    for (auto x : v1) {
        v2.push_back(x * x);
    }
    return v2;
}

int main() {

    std::cout << pow_two(1.4) << "\n";

    std::vector<int> v1 = { 2, 13, 22, 71, 87, 99 };
    for (auto x : pow_two<int>(v1)) {  // вызов перегруженной версии
        std::cout << x << " ";
    }
    std::cout << "\n";


    std::cout << "\n\n\nHello World!\n";
    return 0;
}
