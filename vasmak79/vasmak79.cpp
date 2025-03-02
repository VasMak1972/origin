// vasmak79.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
// В исходном коде существуют определенные недостатки:
// 
// 1. Класс Data перегружен: хранит данные, проверяет и форматирует. Это несоблюдение принципа единственной
//    ответственности SPR (принципы SOLID). (Оставим классу Data только функцию создания сообщения)
// 
// 2. Наличие "толстого" абстрактного класса Printable нарушает принципа разделения интерфейсов ISP (из принципов SOLID).
//    (Разделим его функционал на специальные интерфейсы: PrintAsHTML, PrintAsText, PrintAsJSON)
// 
// 3. Методы, реализуемые в классе-наследнике, printAsHTML(), printAsText(), printAsJSON() выбрасывают исключения. Здесь, возможно
//    нарушается принцип Liskov (из SOLID).(Необходимо от этого избавиться в исправ. коде: разделить валидацию и преобразование)
// 
// 4. Нарушение принципа DRY: повторяющиеся проверки if(format_ != Format::...) в классе Data и их дублирование в
//    функции saveToAsHTML через оператор switch. (Попробуем исправить это через использование шаблона проектирования
//    "Цепочка ответственности". Применим принцип инверсии зависимостей DIP (из набора SOLID), повышая уровень абстракции:
//    заменим функции на соответствующие  классы)
// 
// 
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

enum class Format {
    kText,
    kHTML,
    kJSON,
    kXML,
};

class Data {
protected:
    std::string msg;
    Format format;

public:
    Data(std::string _msg, Format _format) 
        : msg(std::move(_msg)), format(_format) {
    }
    Format getFormat() const { return format; }
    std::string getMsg() const { return msg; }
};



class Printable {
public:
    const Data& data; 
    virtual ~Printable() = default;
    Printable(const Data& _data) : data(_data) {}
    virtual std::string print() const = 0;
};

class PrintAsHTML : public Printable {
public:
    PrintAsHTML(const Data& _data) : Printable(_data) {}

    std::string print() const override {
        return "<html>" + data.getMsg() + "</html>";
    }
};

class PrintAsText : public Printable {
public:
    PrintAsText(const Data& _data) : Printable(_data) {}

    std::string print() const override {
        return data.getMsg();
    }
};

class PrintAsJSON : public Printable {
public:
    PrintAsJSON(const Data& _data) : Printable(_data) {}

    std::string print() const override {
        return "{ \"data\": \"" + data.getMsg() + "\"}";
    }
};




class Saver {
protected:
    std::string filePath;
    Saver* next;

    virtual bool canFormat(const Data& data) const = 0;
    virtual void process(const Data& data) const = 0;

public:
    Saver(std::string path, Saver* _next) : filePath(path), next(_next) {}
    virtual ~Saver() { if(next) delete next; }

    void save(const Data& data) const {
        if (canFormat(data)) {
            process(data);
        }
        else if (next != nullptr) {
            next->save(data);
        }
        else {
            throw std::runtime_error("No handler for this message format!");
        }
    }
};

class SaverToText : public Saver {
public:
    SaverToText(const std::string& path, Saver* _next) : Saver(path, _next) {}

protected:
    bool canFormat(const Data& data) const override {
        return data.getFormat() == Format::kText;
    }

    void process(const Data& data) const override {
        PrintAsText printer(data);
        std::ofstream file(filePath, std::ios::app);
        if (file.is_open()) {
            file << printer.print() << std::endl;
        }
        file.close();
    }
};

class SaverToHTML : public Saver {
public:
    SaverToHTML(const std::string& path, Saver* _next) : Saver(path, _next) {}

protected:
    bool canFormat(const Data& data) const override {
        return data.getFormat() == Format::kHTML;
    }

    void process(const Data& data) const override {
        PrintAsHTML printer(data);
        std::ofstream file(filePath, std::ios::app);
        if (file.is_open()) {
            file << printer.print() << std::endl;
        }
        file.close();
    }
};

class SaverToJSON : public Saver {
public:
    SaverToJSON(const std::string& path, Saver* _next) : Saver(path, _next) {}

protected:
    bool canFormat(const Data& data) const override {
        return data.getFormat() == Format::kJSON;
    }

    void process(const Data& data) const override {
        PrintAsJSON printer(data);
        std::ofstream file(filePath, std::ios::app);
        if (file.is_open()) {
            file << printer.print() << std::endl;
        }
        file.close();
    }
};





int main() {

    Data data1("Hello, Word!", Format::kText);
    Data data2("Hello, Internet!", Format::kHTML);
    Data data3("Hello, JSON!", Format::kJSON);
    //Data data4("Hello, table!", Format::kXML);

    Saver* chain = new SaverToText("text.txt",
                      new SaverToHTML("page.html",
                         new SaverToJSON("data.json", nullptr)));

    chain->save(data1);
    chain->save(data2);
    chain->save(data3);
    //chain->save(data4);

    delete chain;

    std::cout << "Good Day!!!" << std::endl;
    return 0;
}
