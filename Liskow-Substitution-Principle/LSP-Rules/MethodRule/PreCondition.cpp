#include<bits/stdc++.h>
using namespace std;

class User {
    private:
        int password;
    public:


    virtual void setPassword(string  password) {
        if(password.length() < 8) {
            throw invalid_argument("Password is too small and hence weak";)    
        }
        cout<<"password set successfully"; 
    }
};

class AdminUser: public User {
    public:
    void setPassword(String password) {
        if(password.length() < 6) {
            throw invalid_argument("Password is too small and hence weak";)
        }
        cout<<"password set successfully"; 

    }
};
 
int main() {
    User* user = new AdminUser();
    user->setPassword("Admin")

    return 0;
}