#include <iostream>
#include <string>
using namespace std;

class A {
public:
    A(const int val) : val(val) {

    }

    A(const A &obj) {
        val = obj.val;
    }

    A& operator = (const A &obj) {
        if(this != &obj) {
            this->val = obj.val;
        }
        return *this;
    }

private: 
    int val;
};
