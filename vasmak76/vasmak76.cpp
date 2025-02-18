// vasmak76.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>



class CommandFactory {
protected:
    std::string commandType;
public:
    CommandFactory(const std::string& _commandType) : commandType(_commandType) {}
    const std::string& getCommandType() const { return commandType; }
};

class LogCommand {    
public:
    CommandFactory& factory;
    LogCommand(CommandFactory& _factory) : factory(_factory) {}
    virtual ~LogCommand() = default;
    virtual void print(const std::string& message) = 0;
};

class ConsoleLogCommand : public LogCommand {
public:
    ConsoleLogCommand(CommandFactory& _factory) : LogCommand(_factory) {}

    void print(const std::string& message) override {
        std::cout << "Console: " << message << std::endl;
    }
};

class FileLogCommand : public LogCommand {
private:
    std::string filePath;
public:
    FileLogCommand(const std::string& path, CommandFactory& _factory)
        : LogCommand(_factory), filePath(path) {
    }

    void print(const std::string& message) override {
        std::ofstream file(filePath, std::ios::app);
        if (file) {
            file << "File: " << message << std::endl;
        }
        else {
            std::cerr << "File not found";
        }
    }
};

void print(LogCommand& cmd) {

    std::string message = cmd.factory.getCommandType();
    cmd.print(message);
}



int main() {
    CommandFactory factory("open file for writing");

    FileLogCommand fileCmd("log.txt", factory);
    ConsoleLogCommand consoleCmd(factory);

    print(consoleCmd);
    print(fileCmd);





    std::cout << "\n\nGood Day!!!" << std::endl;
    return 0;
}

