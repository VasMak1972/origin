#include <iostream>
#include <string>


class smart_array {
private:
    int* arr;
    int size;
    int index;

public:
    smart_array(int sz) {
        size = sz;
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = 0;
        }
        index = 0;
    }

    smart_array(const smart_array& other) {
        size = other.size;
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = other.arr[i];
        }
    }

    smart_array& operator=(const smart_array& other) {
        if (this == &other) {
            return *this;
        }
        delete[] arr;
        size = other.size;
        index = other.index;
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = other.arr[i];
        }
        return *this;
    }

    void add_element(int num) {
        if (index >= size || index < 0) {
            ;
            throw std::runtime_error("Error: index out of bounds");
        }
        else {
            arr[index] = num;
            std::cout << (index == 0 ? "" : ", ") << arr[index];
            index++;
        }
    }

    int get_element(int& index) {
        if (index >= size || index < 0) {
            throw std::runtime_error("Error: index out of bounds");
        }
        else {
            return arr[index];
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
        //arr.add_element(15);
        std::cout << std::endl;

        smart_array new_arr(3);
        std::cout << "add new_arr = ";
        new_arr.add_element(44);
        new_arr.add_element(34);

        new_arr = arr;
        new_arr.add_element(24);
        //new_arr.add_element(14);
        //new_arr.add_element(4);

        //arr = new_arr;
        //arr.add_element(33);
        //arr.add_element(55);

        std::cout << std::endl;
        std::cout << std::endl;
        for (int i = 0; i < arr.get_size(); i++) {
            std::cout << "arr[" << i << "] = " << arr.get_element(i) << std::endl;
        }
        std::cout << std::endl;
        for (int i = 0; i < new_arr.get_size(); i++) {
            std::cout << "new_arr[" << i << "] = " << new_arr.get_element(i) << std::endl;
        }
    }

    catch (const std::exception& ex) {
        std::cout << std::endl;
        std::cout << ex.what() << std::endl;
    }

    std::cout << "\n\n\nHello World!\n";
    return 0;
}