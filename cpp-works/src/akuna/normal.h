#include <iostream>
#include <string>

using namespace std;

class Base {
public: 
    virtual void A() {
        cout << "Base" << endl;
    }

    virtual void C() {
        cout << "Base Cd" << endl;
    }
};

class Derive : public Base {
public: 
    void A() {
        cout << "Derive" << endl;
    }
};
