// vasmak77.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <vector>
#include <memory>
#include <string>
#include <iostream>
#include <fstream>

class Observer {
public:
    virtual void onWarning(const std::string& message) {}
    virtual void onError(const std::string& message) {}
    virtual void onFatalError(const std::string& message) {}
    virtual ~Observer() = default;
};

class Observable {

private:   
    mutable std::vector<std::weak_ptr<Observer>> observers_;

public:
    void addObserver(const std::weak_ptr<Observer>& observer) {
        observers_.push_back(observer);
    }

    void warning(const std::string& message) const {
        auto it = observers_.begin();
        while (it != observers_.end()) {
            if (auto observer = it->lock()) {
                observer->onWarning(message);
                ++it;
            }
            else {
                it = observers_.erase(it);
            }
        }        
    }

    void error(const std::string& message) const {
        auto it = observers_.begin();
        while (it != observers_.end()) {
            if (auto observer = it->lock()) {
                observer->onError(message);
                ++it;
            }
            else {
                it = observers_.erase(it);
            }
        }        
    }

    void fatalError(const std::string& message) const {
        auto it = observers_.begin();
        while (it != observers_.end()) {
            if (auto observer = it->lock()) {
                observer->onFatalError(message);
                ++it;
            }
            else {
                it = observers_.erase(it);
            }
        }
    }
};


class WarningLogger : public Observer {
public:
    void onWarning(const std::string& message) override {

        std::cout << "Warning: " << message << std::endl;
    }
};

class ErrorLogger : public Observer {
    std::string filePath_;
public:
    explicit ErrorLogger(const std::string& filePath) : filePath_(filePath) {}

    void onError(const std::string& message) override {

        std::ofstream file(filePath_, std::ios::app);
        if (file) {
            file << "Error: " << message << std::endl;
        }
    }
};

class FatalErrorLogger : public Observer {
    std::string filePath_;
public:
    explicit FatalErrorLogger(const std::string& filePath) : filePath_(filePath) {}

    void onFatalError(const std::string& message) override {

        std::cout << "Fatal Error: " << message << std::endl;

        std::ofstream file(filePath_, std::ios::app);
        if (file) {
            file << "Fatal Error: " << message << std::endl;
        }
    }
};



int main() {

    Observable observable;

    auto warningLogger = std::make_shared<WarningLogger>();
    observable.addObserver(warningLogger);

    auto errorLogger = std::make_shared<ErrorLogger>("error_log.txt");
    observable.addObserver(errorLogger);

    auto fatalLogger = std::make_shared<FatalErrorLogger>("fatal_log.txt");
    observable.addObserver(fatalLogger);

    observable.warning("Disk space low");
    observable.error("Invalid input");
    observable.fatalError("System crash");


    std::cout << "\n\n\nGood Day!!!" << std::endl;
    return 0;
}

