#include<bits/stdc++.h>
using namespace std;

class Car {
    protected:
        int speed;
    public:
        Car() {
            speed = 0;
        }

        void accelarate() {
            cout<<"Accelerating"<<endl;
            speed += 23;
        }

        // Post Condition
        virtual void brake() {
            cout<<"Braking"<<endl;
            speed -= 20;
        }
};
    // SubClass must strengtgen the base class`
    class HyperCar: public Car {
        private:
            int charge;

        public:
            HyperCar() : Car() {
                charge = 0;
            }

            // PostCondition:Speed must reduce after brake
            // PostCondition:Charge must increse

            void brake() {
                cout<<"Applying brake"<<endl;
                speed -= 20;
                charge += 10;    
            };
    }
int main() {

    return 0;
}