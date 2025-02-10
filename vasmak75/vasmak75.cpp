// vasmak75.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <map>
#include <string>
#include <memory>


class VeryHeavyDatabase {
public:
    std::string GetData(const std::string& key) const noexcept {
        return "Very Big Data String: " + key;
    }
};

class CacheProxyDB : VeryHeavyDatabase {
private:
    std::unique_ptr<VeryHeavyDatabase> real_db_;
    //VeryHeavyDatabase* real_db_;
    std::map<std::string, std::string> cache_;

public:
    CacheProxyDB(std::unique_ptr<VeryHeavyDatabase> real_object) : real_db_(std::move(real_object)) {}

    std::string GetData(const std::string& key) noexcept {
        if (cache_.find(key) == cache_.end()) {
            std::cout << "Get from real DB\n";
            cache_[key] = real_db_->GetData(key);
        }
        else {
            std::cout << "Get from cache DB\n";
        }
        return cache_.at(key);
    }
};

static std::unique_ptr<CacheProxyDB> initCacheProxyDB() {

    auto originDB = std::make_unique<VeryHeavyDatabase>();
    return std::make_unique<CacheProxyDB>(std::move(originDB));    
}


class TestDB : VeryHeavyDatabase {
private:
    std::unique_ptr<VeryHeavyDatabase> real_db_;
public:
    TestDB(std::unique_ptr<VeryHeavyDatabase> real_object) : real_db_(std::move(real_object)) {}

    std::string GetData(const std::string& key) noexcept {
        return "Corrected test data\n";
    }
};

static std::unique_ptr<TestDB> initTestDB() {

    auto originDB = std::make_unique<VeryHeavyDatabase>();
    return std::make_unique<TestDB>(std::move(originDB));
}



class OneShotDB : VeryHeavyDatabase {
private:
    std::unique_ptr<VeryHeavyDatabase> real_db_;
    std::map<std::string, size_t> call_counts_;
    size_t max_shots_;

public:
    OneShotDB() {};
    explicit OneShotDB(std::unique_ptr<VeryHeavyDatabase> real_object, size_t shots)
        : real_db_(std::move(real_object)), max_shots_(shots) {
    }

    std::string GetData(const std::string& key) noexcept {
        size_t& count = call_counts_[key];
        if (count < max_shots_) {
            count++;
            return real_db_->GetData(key);
        }
        else {
            return "error";
        }
    }
};



static std::unique_ptr<OneShotDB> initOneShotDB(std::unique_ptr<VeryHeavyDatabase> real_object = nullptr, size_t shots = 1) {
    if (!real_object) {
        real_object = std::make_unique<VeryHeavyDatabase>();
    }
    return std::make_unique<OneShotDB>(std::move(real_object), shots);
}




int main() {   

    auto db = initCacheProxyDB();
    std::cout << db->GetData("key1") << std::endl;
    std::cout << db->GetData("key1") << std::endl;
    std::cout << db->GetData("key2") << std::endl;
    std::cout << db->GetData("key2") << std::endl;
    std::cout << std::endl;

    auto test_db = initTestDB();
    std::cout << test_db->GetData("key1") << std::endl;
    std::cout << test_db->GetData("key2") << std::endl;
    std::cout << test_db->GetData("key3") << std::endl;
    std::cout << std::endl;

    //OneShotDB access db;
    auto limit_db = initOneShotDB(std::make_unique<VeryHeavyDatabase>(), 3);
    std::cout << limit_db->GetData("key") << std::endl; // Вывод: Very Big Data String: key
    std::cout << limit_db->GetData("key") << std::endl; // Вывод: Very Big Data String: key
    std::cout << limit_db->GetData("key") << std::endl; // Вывод: Very Big Data String: key
    std::cout << limit_db->GetData("key") << std::endl; // Вывод: error

    std::cout << "\n\n\n Good Day!!!" << std::endl;
    return 0;
}





/*
// first version
class VeryHeavyDatabase {
public:
    std::string GetData(const std::string& key) const noexcept {
        return "Very Big Data String: " + key;
    }
};


class CacheProxyDB : VeryHeavyDatabase {
private:
    std::map<std::string, std::string> cache_;
    VeryHeavyDatabase* real_db_;
public:
    explicit CacheProxyDB(VeryHeavyDatabase* real_object) : real_db_(real_object) {}

    std::string GetData(const std::string& key) noexcept {
        if (cache_.find(key) == cache_.end()) {
            std::cout << "Get from real DB\n";
            cache_[key] = real_db_->GetData(key);
        }
        else {
            std::cout << "Get from cache DB\n";
        }
        return cache_.at(key);
    }

};

class TestDB : VeryHeavyDatabase {
private:
    VeryHeavyDatabase* real_db_;
public:
    explicit TestDB(VeryHeavyDatabase* real_object) : real_db_(real_object) {}

    std::string GetData(const std::string& key) noexcept {
    return "test_data\n";
    }
};




int main() {

    auto real_db = VeryHeavyDatabase();
    auto cached_db = CacheProxyDB(std::addressof(real_db));
    auto test_db = TestDB(std::addressof(real_db));

    std::cout << cached_db.GetData("key1") << std::endl;
    std::cout << cached_db.GetData("key1") << std::endl;

    std::cout << cached_db.GetData("key2") << std::endl;
    std::cout << cached_db.GetData("key2") << std::endl;

    std::cout << test_db.GetData("key1") << std::endl;

    return 0;
}
*/




