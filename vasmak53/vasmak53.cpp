// vasmak53.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include <iostream>
#include <vector>
#include <memory>


class tridiagonal_matrix
{
public:
    std::vector<double> m_down;
    std::vector<double> m_upper;
    std::vector<double> m_middle;

    tridiagonal_matrix(
        const std::vector<double>& down,
        const std::vector<double>& upper,
        const std::vector<double>& middle) : m_down{ down }, m_upper{ upper }, m_middle{ middle } {};

    ~tridiagonal_matrix() { std::cout << "destructor called\n"; }

    std::unique_ptr<tridiagonal_matrix> clone() {

        std::unique_ptr<tridiagonal_matrix> ptr_clone(new tridiagonal_matrix(m_down, m_upper, m_middle));
        return ptr_clone;
    }
};


int main()
{
    auto down = std::vector<double>{ -4.0, 5.0 };
    auto upper = std::vector<double>{ 14.0, 8.0 };
    auto middle = std::vector<double>{ 3.0, 1.0, 7.0 };
    auto matrix = std::make_unique<tridiagonal_matrix>(
        down,
        upper,
        middle
    );


    //for (const auto & items : *matrix)) //Здраствуйте! Скажите, пожалуйста!
      //for (const auto & item : items)   //Можно ли как-то так рапечатать объект matrix
          //std::cout << item << " ";     //,например, как обычную матрицу или нет?
      //}
    //}

    std::cout << "matrix: " << std::endl;
    for (const auto& item : matrix->m_down) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
    for (const auto& item : matrix->m_middle) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
    for (const auto& item : matrix->m_upper) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;


    auto matrix_clone = matrix->clone();


    std::cout << "matrix_clone: " << std::endl;
    for (const auto& item : matrix_clone->m_down) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
    for (const auto& item : matrix_clone->m_middle) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
    for (const auto& item : matrix_clone->m_upper) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    return 0;
    std::cout << "\n\n\nHello World!\n";
}