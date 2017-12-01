#include <iostream>
#include <string.h>

using namespace std;

void newBuffer(char* outBuffer, size_t sz) { // outBuffer pointer value is address
    outBuffer = new char[sz]; // address will change here and allocate memory
}

class MyBuffer { // raii solution for managing buffer 
public: 
    MyBuffer(const char *buf, size_t len) { // initialize with acquire resource
        buffer = new char[len];
        memset(buffer, 0, len);
        strncpy(buffer, buf, len);
    }

    ~MyBuffer() { // destructor with delete resource of buffer
        delete buffer;
    }

    friend ostream& operator << (ostream& os, const MyBuffer &obj) { // output function with << overloading
        os << obj.buffer;
        return os;  
    }

private: 
    char *buffer;

};

void t1_2() {
    const char* kung = "KUNG";
    size_t len = strlen(kung);
    MyBuffer foo = MyBuffer(kung, len); // acquire resource when initialize
    cout << foo << endl; // output object by operator overloading
    // destructor will be called before block end
}

void t1() {
    const char* kung = "KUNG";
    const int *p = new int(4);
    delete p;
    size_t len = strlen(kung);
    char *foo;
    

    newBuffer(foo, len); // foo will not be change after this function
    memset(foo, 0, len+1); // 
    strncpy(foo, kung, len);

    cout << foo << endl;
}



/////////// a)



void newBuffer(char** outBuffer, size_t sz) {  // use pointer to pointer 
    *outBuffer = new char[sz];
// foo pointer can be change by this way.
} 


void t1_3() {

    const char* kung = "KUNG"; 
    char* foo = nullptr; //better to initialize to null

    size_t len = strlen(kung); 
    newBuffer(foo, len+1); // send len+1 instead len
    memset(foo, 0, len+1); 
    strncpy(foo, kung, len); 
    cout << foo << endl; 

    // delete foo pointer and set to nullptr in case of memory leak
    delete foo; 
    foo = nullptr;
} 
