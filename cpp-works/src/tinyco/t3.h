#include <vector>
#include <string>
#include <iostream>

using namespace std;

class MyClass {
public:
    MyClass() {
        str = "";
    }

    void setString(const string &s) {
        str = s;
    }

    void printString() {
        cout << str;
    }

private:
    string str;
};


void t3() {
    MyClass *a = new MyClass(); // create a MyClass() object, create pointer "a" point to this Myclass() object
    vector<MyClass> myVector; // create a vector that can store MyClass objects
    myVector.push_back(*a); // copy the MyClass() object of pointer "a" into myVector[0]

    MyClass b = myVector[0]; // create a new MyClass object "b" copy from myVector[0]

    a->setString("Hello World"); // set the string of MyClass() object pointed by "a"
    b.setString("Goodbye World"); // set the string of MyClass() object "b"

    a->printString(); // output "Hello World"
    b.printString(); // output "Goodbye World"
}