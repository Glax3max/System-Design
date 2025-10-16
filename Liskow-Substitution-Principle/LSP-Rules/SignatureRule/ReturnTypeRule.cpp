#include<bits/stdc++.h>

using namespace std;

// Return Type Rule :
// Subtype override method return type should be either identical 
// or narrowed then the parent method's return type.
// This is also called as return type covariance
// C++ enfoces this by covariance

class Animal {
    // some common Animal method
};

class Dog:public Animal {
    // Additional Dog method specific to Dogs
};

class Parent {
public:
    virtual Animal* getAnimal() {
        cout<<"Parent :Returning Animal instant";
        return new Animal;
    }
};

class Child:public Parent{
public:
    Animal* getAnimal() override {
        cout<<"Child : Returning Dog instance"<<endl;
        return new Dog();
    }
};

class Client{
private: 
    Parent* p;
public:
    Client(Parent* p) {
        this->p = p;
    }
    void takeAnimal() {
        p->getAnimal();
    }
};
int main() {
    Parent* parent =  new Parent();
    Child* child = new Child;

    Client* client = new Client(child);
    client->takeAnimal();
    return 0;
}