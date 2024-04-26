#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main() {
	int elm = 0;
	std::vector<int> vec;
	size_t size;
	std::cout << "Enter number elements: ";
	std::cin >> size;
	vec.reserve(size);

	std::cout << "Enter non-unique elements: " << std::endl;
	for (size_t i = 0; i != size; ++i) {
		std::cin >> elm;
		vec.push_back(elm);
	}

	std::sort(vec.rbegin(), vec.rend());
	auto last = std::unique(vec.begin(), vec.end());
	vec.resize(std::distance(vec.begin(), last));

	std::cout << "Unique number elements: ";
	for (auto& element : vec) {
		std::cout << element << " ";
	}



	std::cout << "\n\n\nHello World!\n";
	return 0;
}
