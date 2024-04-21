#include <iostream>
#include <string>

template <typename T>
 class Wrapper {
 public:
    T* arr;
    int n;
    int m;

    T& operator[](int j) {
        if (j < 0 || j >= m) {
            throw std::out_of_range("Index out of range");
        }
        return arr[j];
    }
};

template <typename T>
 class Table {
 private:
    T** arr;
    int size_n;
    int size_m;

 public:
    Table(int n, int m) {

        size_n = n;
        size_m = m;
        arr = new T * [n];
        for (int i = 0; i < n; i++) {
            arr[i] = new T[m];
        }
        for (int i = 0; i < size_n; i++) {
            for (int j = 0; j < size_m; j++) {
                arr[i][j] = 0;
            }
        }
    }


    Wrapper<T> operator[](int i) {
        if (i < 0 || i >= size_n) {
            throw std::out_of_range("Index out of range");
        }
        Wrapper<T> result;
        result.arr = arr[i];
        result.m = size_m;
        return result;
    }


    Table(const Table& other) {
        size_n = other.size_n;
        size_m = other.size_m;
        arr = new T * [size_n];
        for (int i = 0; i < size_n; i++) {
            arr[i] = new T[size_m];
        }
        for (int i = 0; i < size_n; i++) {
            for (int j = 0; j < size_m; j++) {
                arr[i][j] = other.arr[i][j];
            }
        }
    }

    Table& operator=(Table& other) {
        if (this == &other) {
            return *this;
        }
        for (int i = 0; i < size_n; i++) {
            delete[] arr[i];
        }
        delete[] arr;

        size_n = other.size_n;
        size_m = other.size_m;

        arr = new T * [size_n];
        for (int i = 0; i < size_n; i++) {
            arr[i] = new T[size_m];
        }
        for (int i = 0; i < size_n; i++) {
            for (int j = 0; j < size_m; j++) {
                arr[i][j] = other.arr[i][j];
            }
        }
        return *this;
    }


    Wrapper<T>  Size() {
        Wrapper<T>  size;
        size.n = size_n;
        size.m = size_m;
        return size;
    }

    ~Table() {
        for (int i = 0; i < size_n; i++) {
            delete[] arr[i];
        }
        delete[] arr;
    }
};


int main() {

    try {
        Table<int> table(2, 3);

        //auto test = table;
        Table<int> test(4, 3);

        std::cout << "add table = " << std::endl;
        std::cout << std::endl;
        table[0][0] = 21;
        table[0][1] = 12;
        table[0][2] = 23;
        table[1][0] = 43;
        table[1][1] = 54;
        table[1][2] = 65;
        //table[1][3] = 6;

        test[0][0] = 21;
        test[1][1] = 12;
        test[0][2] = 23;
        test[2][2] = 43;
        test[2][1] = 54;
        test[1][2] = -1;
        test[3][0] = 21;
        test[2][1] = 12;
        test[3][2] = 23;
        //table[4][3] = 6;       

        //table = test;     
        //test = table;


        for (int i = 0; i < table.Size().n; i++) {
            for (int j = 0; j < table.Size().m; j++) {
                std::cout << table[i][j] << "\t";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;


        for (int i = 0; i < test.Size().n; i++) {
            for (int j = 0; j < test.Size().m; j++) {
                std::cout << test[i][j] << "\t";
            }
            std::cout << std::endl;
        }


    }


    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }


    std::cout << "\n\n\nHello World!\n";
    return 0;
}
