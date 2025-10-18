#include<iostream>
using namespace std;
class MongoDBDatabase {
    public:
        void saveToMongo(string data) {
            cout<<"Executing MongoDB function: Db.users.insert({name:'"<<data<<"'})"<<endl;
        }
};

class MySQLDatabase {
    public:
        void saveToSql(string data) {
            cout<<"Executing SQL function: Db.users.insert({name:'"<<data<<"'})"<<endl;
        }
};

class UserService {
    private:
        MySQLDatabase sqlDb;
        MongoDBDatabase mongoDb;

    public:
        void storeUserToSQL(string user) {
            sqlDb.saveToSql(user);
        }

        void storeUserToMongo(string user) {
            mongoDb.saveToMongo(user);
        }
};

int main() {
    UserService service;
    service.storeUserToMongo("Raj");  
    service.storeUserToSQL("Abhi");  

    return 0;
}