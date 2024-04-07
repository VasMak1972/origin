#include <iostream>
#include <string>


class smart_array {
private:
    int* arr;
    int size;
    int i;

public:
    smart_array(int sz) {
        size = sz;
        arr = new int[size];
        for (int j = 0; j < size; j++) {
            arr[j] = 0;
        }
        i = 0;
    }

    void add_element(int num) {
        if (i >= size || i < 0) {
            ;
            throw std::runtime_error("Error: index out of bounds");
        }
        else {
            arr[i] = num;
            std::cout << (i == 0 ? "" : ", ") << arr[i];
            i++;
        }
    }

    int get_element(int i) {
        if (i >= size || i < 0) {
            throw std::runtime_error("Error: index out of bounds");
        }
        else {
            return arr[i];
        }
    }

    int get_size() {
        return size;
    }

    ~smart_array() {
        delete[] arr;
    }
};


int main() {

    try {
        smart_array arr(5);
        std::cout << "add arr = ";
        arr.add_element(1);
        arr.add_element(4);
        arr.add_element(155);
        arr.add_element(14);
        arr.add_element(15);
        //arr.add_element(16);

        std::cout << std::endl;
        std::cout << "get arr = ";
        std::cout << arr.get_element(1) << std::endl;

        std::cout << std::endl;
        for (int i = 0; i < arr.get_size(); i++) {
            std::cout << "arr[" << i << "] = " << arr.get_element(i) << std::endl;
        }
    }

    catch (const std::exception& ex) {
        std::cout << std::endl;
        std::cout << ex.what() << std::endl;
    }


    std::cout << "\n\n\nHello World!\n";
    return 0;
}
