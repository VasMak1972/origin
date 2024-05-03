// vasmak54.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include <iostream>
#include <vector>
#include <memory>

class node
{
public:
    int m_value;
    std::weak_ptr<node> parent;
    node(int value) : m_value{ value } {};
    ~node() { std::cout << "destructor called\n"; }
};

int main()
{
    {
        auto node1 = std::make_shared<node>(1);
        auto node2 = std::make_shared<node>(2);
        std::cout << node1.use_count() << "\n";
        std::cout << node2.use_count() << "\n";
        std::cout << std::endl;

        node1->parent = node2;
        node2->parent = node1;
        std::cout << node1.use_count() << "\n";
        std::cout << node2.use_count() << "\n";
        std::cout << std::endl;
    }

    std::cout << "\n\n\nHello World!\n";
    return 0;
}