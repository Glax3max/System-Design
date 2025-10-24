#include<bits/stdc++.h>
using namespace std;
class Burger{
    public:
        virtual void prepare() = 0;//pure virtual function
        virtual ~Burger(){} //virtual destructor
};

class BasicBurger:public Burger {
    public:
        void prepare() override {
            cout<<"Preparing Basic burger"<<endl;
        }
};

class StandardBurger:public Burger {
    public:
        void prepare() override {
            cout<<"Preparing Standard burger"<<endl;
        }
};


class PremiumBurger:public Burger {
    public:
        void prepare() override {
            cout<<"Preparing Premium burger"<<endl;
        }
};


class Factory{
    public:
        Burger* createBurger(string &type) {
            if(type == "basic") {
                return new BasicBurger();
            }else if(type == "standard") {
                return new StandardBurger();
            }else if(type == "premium") {
                return new PremiumBurger();
            }else{
                cout<<"Invalid burger type!"<<endl;
                return nullptr;
            }
        }
};


int main() {
    string type = "standard";
    Factory* burgerFactory = new Factory();

    Burger* burger = burgerFactory->createBurger(type);
    burger->prepare();
    
    return 0;
}
