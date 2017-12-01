#include <iostream>

using namespace std;


class Vehicle {
public: 
    Vehicle() {

    }
    virtual void Print() {
        cout << "head";
    }
};

class Car : public Vehicle {
public:
    Car() {

    }

    void Print() {
        cout << "car";
    }

};



