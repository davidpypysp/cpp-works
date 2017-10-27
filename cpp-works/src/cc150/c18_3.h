#include <iostream>

using namespace std;

class Lock {
public:
    Lock() {}
    ~Lock() {}
    void AcquireLock() {}
    void ReleaseLock() {}
};


template <class T> class Singleton {
private:
    static Lock lock;
    static T* object;
protected:
    Singleton() {};
public: 
    static T* Instance();


};

Lock Singleton::lock;

T* Singleton::Instance() {
    if(object == nullptr) {
        lock.AcquireLock();
        if(object == nullptr) {
            object = new T;
        }
        lock.releaseLock();
    }
    return object;
};
