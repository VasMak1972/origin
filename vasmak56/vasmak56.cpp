#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <cstdlib>

class BigInt {
private:
    std::string n_str;

public:
    BigInt(const std::string& nstr) : n_str(nstr) {}

    BigInt(const BigInt&& other) noexcept {
        n_str = other.n_str;
    }

    BigInt& operator=(const BigInt&& other) noexcept {
        if (this != &other) {
            n_str = std::move(other.n_str); ;
        }
        return *this;
    }

    BigInt& operator=(const BigInt& other) {
        if (this != &other) {
            n_str = std::move(other.n_str);
        }
        return *this;
    }

    ~BigInt() {}

    size_t get_size() {
        return n_str.size();
    }

    /////////////////////////////////////////////////////////////////////
    // ОПЕРАТОР СЛОЖЕНИЯ
    friend BigInt operator+(const BigInt& bigint1, const BigInt& bigint2) {

        int memory = 0;
        int size_dif = 0;
        std::string stn_1 = bigint1.n_str;
        std::string stn_2 = bigint2.n_str;
        size_t size_1 = stn_1.size();
        size_t size_2 = stn_2.size();
        int size = std::max(size_1, size_2);

        // Выравнивание разрядов в числах 
        std::string summa;
        summa.insert(0, size, '0');
        if (size_2 > size_1) {
            size_dif = size_2 - size_1;
            stn_1.insert(0, size_dif, '0');
        }
        else if (size_1 > size_2) {
            size_dif = size_1 - size_2;
            stn_2.insert(0, size_dif, '0');
        }

        //Поразрядное сложение чисел
        int i = 0;
        int sum = 0;
        for (i = size - 1; i >= 0; --i) {
            int n_1 = stoi(std::string(1, stn_1[i]));
            int n_2 = stoi(std::string(1, stn_2[i]));
            sum = n_1 + n_2 + memory;
            memory = 0;
            if (sum >= 10) {
                int num = sum - 10;
                std::string tmp = std::to_string(num);
                summa[i] = tmp[0];
                memory = 1;
            }
            else {
                std::string tmp = std::to_string(sum);
                summa[i] = tmp[0];
            }
            //std::cout << summa[i] << " " << std::endl;     
        }
        //Определение порядка   результата сложения
        if (sum >= 10 && i < 0) {
            summa.insert(0, 1, '1');
        }
        return BigInt(summa);
    }

    /////////////////////////////////////////////////////////////////////
    // ОПЕРАТОР ВЫЧИТАНИЯ

    friend BigInt operator-(const BigInt& bigint1, const BigInt& bigint2) {

        int size_dif = 0;
        std::string stn_1 = bigint1.n_str;
        std::string stn_2 = bigint2.n_str;
        size_t size_1 = stn_1.size();
        size_t size_2 = stn_2.size();
        int size = std::max(size_1, size_2);

        std::string dif;
        std::string tmp;
        dif.insert(0, size, '0');
        tmp.insert(0, size, '0');

        // Выравнивание разрядов в числах 
        if (size_1 > size_2) {
            size_dif = size_1 - size_2;
            stn_2.insert(0, size_dif, '0');
        }
        else if (size_2 > size_1) {
            size_dif = size_2 - size_1;
            stn_1.insert(0, size_dif, '0');
        }
        //Поразрядное вычитание чисел    
        int dfr = 0;
        int memory = 0;
        int n_1 = stoi(std::string(stn_1.begin(), stn_1.end()));
        int n_2 = stoi(std::string(stn_2.begin(), stn_2.end()));

        if (n_2 > n_1) {
            tmp = std::move(stn_1);
            stn_1 = std::move(stn_2);
            stn_2 = std::move(tmp);
        }
        int i;
        for (i = size - 1; i >= 0; --i) {
            int n_1 = stoi(std::string(1, stn_1[i]));
            int n_2 = stoi(std::string(1, stn_2[i]));
            dfr = n_1 - n_2 - memory;
            memory = 0;

            if (dfr < 0) {
                int num = dfr + 10;
                std::string tmp = std::to_string(num);
                dif[i] = tmp[0];
                memory = 1;
            }
            else if (dfr >= 0) {
                std::string tmp = std::to_string(dfr);
                dif[i] = tmp[0];
            }
        }
        //Выравнивание разрядов в числах

        int k = 0;
        while (dif[k] == '0' && k < size - 1) {
            ++k;
        }
        if (k > 0) {
            dif.erase(0, k);
            dif.insert(0, k, ' ');
        }
        //Определение знака результата вычитания
        if (n_2 > n_1 && i < 0) {
            dif.insert(0, 1, '-');
        }

        return BigInt(dif);
    }

    /////////////////////////////////////////////////////////////////////
    // ОПЕРАТОР УМНОЖЕНИЯ
    friend BigInt operator*(const BigInt& bigint1, const BigInt& bigint2) {

        std::string stn_1 = bigint1.n_str;
        std::string stn_2 = bigint2.n_str;
        size_t size_1 = stn_1.size();
        size_t size_2 = stn_2.size();
        int size = std::max(size_1, size_2);
        int size_dif = size_1 - size_2;
        size_dif = std::abs(size_dif);

        // Выравнивание разрядов в числах    
        if (size_2 > size_1) {
            stn_1.insert(0, size_dif, '0');
        }
        else if (size_1 > size_2) {
            stn_2.insert(0, size_dif, '0');
        }

        //Поразрядное умножение чисел  
        int mult = 0;
        int memory = 0;

        std::string mltp;
        mltp.insert(0, size, '0');
        std::string temp;
        temp.insert(0, size_1 + size_2 - 1, '0');

        int i = 0;
        int j = 0;
        int l = 0;
        auto tmp = BigInt(temp);

        for (i = size - 1; i >= 0; i--) {
            mltp.assign(size, '0'); // Обнуление массива mltp для промежуточных результатов
            for (j = size - 1; j >= 0; j--) {

                int n_1 = stoi(std::string(1, stn_1[j]));
                int n_2 = stoi(std::string(1, stn_2[i]));
                mult = (n_2 * n_1) + memory;
                memory = 0;

                if (mult <= 9) {
                    std::string tmp = std::to_string(mult);
                    mltp[j] = tmp[0];
                }
                else if (mult >= 10) {
                    int num = mult % 10;
                    std::string tmp = std::to_string(num);
                    mltp[j] = tmp[0];
                    memory = (mult - num) / 10;
                }
            }

            //Определение первого разряда в промежуточном результате
            if (mult >= 10 && j < 0) {
                std::string s = std::to_string(memory);
                mltp.insert(0, 1, s[0]);
                mltp.insert(0, i, '0');
            }
            else {
                mltp.insert(0, i, '0');
            }
            //Выравнивание разрядов в следующем промежуточном результате    
            if (i < size - 1) {
                l++;
                mltp.insert(mltp.end(), l, '0');
            }

            std::cout << mltp << std::endl; //Вывод промежуточных результатов

            auto temp_sum = tmp + BigInt(mltp); //Сложение промежуточных результатов 
            tmp = std::move(temp_sum);
            mltp.assign(tmp.n_str);
            memory = 0;
        }

        // Определение первого разряда в результате произведения
        if (mult >= 10 && i < 0) {
            std::string s = std::to_string(memory);
            mltp.insert(0, 1, s[0]);
        }

        // Удаление нулей перед первым разрядом в числе
        int k = 0;
        while (mltp[k] == '0' && k < size_1 + size_2) {
            k++;
        }
        if (k > 0) {
            mltp.erase(0, k);
            //mltp.insert(0, k, ' ');
        }

        std::string simbol_;
        simbol_.insert(0, size_1 + size_2, '-');
        std::cout << simbol_ << std::endl;

        return BigInt(mltp);
    }
    /////////////////////////////////////////////////////////////////////
    // ОПЕРАТОР ВЫВОДА
    friend std::ostream& operator<<(std::ostream& ost, const BigInt& bigint) {
        ost << bigint.n_str;
        return ost;
    }

};


int main() {

    auto num_1 = BigInt("999230");
    auto num_2 = BigInt("99945609");

    std::cout << num_1 << std::endl;
    std::cout << num_2 << std::endl;


    // Символы для вывода результатов 
    int size_1 = num_1.get_size();
    int size_2 = num_2.get_size();
    int max = std::max(size_1, size_2);
    std::string simbol_;
    simbol_.insert(0, max + 1, '-');
    std::cout << simbol_ << std::endl;

    // Результаты выполнения операций 
    auto result_plus = num_1 + num_2;
    std::cout << result_plus << std::endl;
    std::cout << std::endl;

    auto result_minus = num_1 - num_2;
    std::cout << result_minus << std::endl;
    std::cout << std::endl;

    auto result_mult = num_1 * num_2;
    std::cout << result_mult << std::endl;
    std::cout << std::endl;



    std::cout << "\n\n\nHello World!\n";
    return 0;
}
