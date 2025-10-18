#include<iostream>
using namespace std;

class Shape{
    public:
    virtual double area() = 0;
    virtual double volume() = 0;
};

class Square : Shape{
    private:
        double s;
    public:
    Square(double s) {
        this.s = s;
    }
    double area() override {
        return s*s;
    }

    double volume() override {
        throw logic_error("2D shape can not have volume"); //Unnecessary
    }
};

class rectangle:Shape{
    private:
        double l,b;
    public:
    Square(double l,double b) {
        this.l = l;
        this.b = b;
    }
    double area() override {
        return l*b;
    }

    double volume() override {
        throw logic_error("2D shape can not have volume"); //Unnecessary
    }
};

class cube:Shape{
    private:
        double s;
    public:
    Square(double s) {
        this.s = s;
    }
    double area() override {
        return 6*s*s;
    }

    double volume() override {
        return s*s*s;
    }
};
int main() {

    return 0;
}