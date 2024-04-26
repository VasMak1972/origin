#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>


int main() {

    int sum;
    std::string str;
    std::cout << "Enter a string: ";
    std::getline(std::cin, str);

    int size = str.length();
    std::vector<std::pair<char, int>> vec(size);
    std::cout << std::endl;

    for (int i = 0; i < size; i++) {
        sum = 0;
        for (int j = 0; j < size; j++) {
            if (str[i] == str[j]) {
                sum++;
            }
        }
        vec[i].first = str[i];
        vec[i].second = sum;
    }

    std::sort(vec.begin(), vec.end(),
        [](const auto& a, const auto& b) {return a.second > b.second; });

    auto last = std::unique(vec.begin(), vec.end());

    vec.erase(last, vec.end());


    for (size_t i = 0; i != vec.size(); ++i) {
        std::cout << vec[i].first << " " << vec[i].second << std::endl;
    }

    std::cout << "\n\n\nHello World!\n";
    return 0;
}
