#include<iostream>
using namespace std;

// Abstraction (Interface)
class Database{
    public:
        virtual void save(string data) = 0; //pure virtual function
};

// MongoDB Implemented : (Low level module)
class MongoDBDatabase : public Database{
    public:
        void save(string data) override{
            cout<<"Executing MongoDB function: Db.users.insert({name:'"<<data<<"'})"<<endl;
        }
};

// MySQLDB Implemented : (Low level module)
class MySQLDatabase : public Database{
    public:
        void save(string data) override {
            cout<<"Executing SQL function: Db.users.insert({name:'"<<data<<"'})"<<endl;
        }
};

// High-Level module (Now loosely coupled)
class UserService {
    private:
    Database* db; //Dependency Injection

    public:
        UserService(Database* database) {
            db = database;
        }

        void storeUser(string user) {
            db->save(user);
        }
};

int main() {
    MySQLDatabase mysql;
    MongoDBDatabase mongodb;

    UserService service1(&mysql);
    service1.storeUser("aaditya");

    return 0;
}