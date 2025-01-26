// vasmak73.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>



struct factorSql {

    std::string tableName;

    std::string columnNames;
    bool columnNamesIsEmpty = true;

    std::string whereCondition = "";
    bool whereConditionIsOne = true;

    std::string query;
};


class SqlSelectQueryBuilder {

protected:
    factorSql factor;

public:
    SqlSelectQueryBuilder() {
        factor.tableName = "";
        factor.columnNames = "*";
        factor.whereCondition = "";
        factor.query = "SELECT";
    }

    SqlSelectQueryBuilder& addTable(std::string _tableName) {
        factor.tableName = _tableName;
        return *this;
    }

    SqlSelectQueryBuilder& addColumn(std::string _columnName) {
        if (factor.columnNamesIsEmpty)
        {
            factor.columnNames = _columnName;
            factor.columnNamesIsEmpty = false;
        }
        else
        {
            factor.columnNames += ", " + _columnName;
        }
        return *this;
    }

    SqlSelectQueryBuilder& addColumns(const std::vector<std::string>& columns) noexcept {
        for (auto& column : columns) {
            if (factor.columnNamesIsEmpty) {
                factor.columnNames = column;
                factor.columnNamesIsEmpty = false;
            }
            else {
                factor.columnNames += ", " + column;
            }
        }
        return *this;
    };


    SqlSelectQueryBuilder& addFrom(std::string _tableName)
    {
        factor.tableName = _tableName;
        return *this;
    }

    SqlSelectQueryBuilder& addWhere(std::string _columnName, std::string _value)
    {
        if (factor.whereConditionIsOne)
        {
            factor.whereCondition += _columnName + "=" + _value;
            factor.whereConditionIsOne = false;
        }
        else
        {
            factor.whereCondition += " AND " + _columnName + "=" + _value;
        }
        return *this;
    }

    SqlSelectQueryBuilder& addWheres(const std::map<std::string, std::string>& kv) {
        for (auto& it : kv) {
            if (factor.whereConditionIsOne) {
                factor.whereCondition += it.first + "=" + it.second;
                factor.whereConditionIsOne = false;
            }
            else {
                factor.whereCondition += " AND " + it.first + "=" + it.second;
            }
        }
        return *this;
    };


    std::string buildQuery() {
        factor.query += " " + factor.columnNames + " FROM " + factor.tableName + " WHERE " + factor.whereCondition + ";";
        return factor.query;
    }

};

int main() {

    SqlSelectQueryBuilder query_builder;

    query_builder.addFrom("students");
    
    query_builder.addColumns(std::vector<std::string>{"name", "phone"});
    
    query_builder.addWheres(std::map<std::string, std::string>{{"id", "42"}, { "name", "John" }});

    std::cout << query_builder.buildQuery();


    std::cout << "\n\n\n\n\nHello World!\n";
    return 0;
}
