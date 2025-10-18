#include<iostream>
using namespace std;
    class TwoDimensionalShape{
        public:
        virtual double area() = 0;
    };

    class ThreeDimensionalShape{
        public:
        virtual double area() = 0;
        virtual double volume() = 0;
    };

    class square:public TwoDimensionalShape {
        private:
            double side;
        public:
        square(double s) :side(s) {}

        double area() override {
            return side*side;
        }
    };

    class rectangle:public TwoDimensionalShape {
        private:
            double length,width;
        public:
        rectangle(double l,double w) : length(l), width(w) {}
        double area() override {
            return length*width;
        }
    };

    class cube:public ThreeDimensionalShape{
        private:
            double side;
        public:
            cube(double s) : side(s){}
            
            double area() override {
                return 6*side*side;
            }

            double volume() override {
                return side*side*side;
            }
    };
int main() {
    TwoDimensionalShape* sq = new square(34);
    cout<<sq->area();
    return 0;
}