#include <iostream>
#include <mutex>
#include <queue>

using namespace std;

template <class T>
class SafeQueue {
    queue<T> q;
    mutex m;

public: 
    SafeQueue() {}

    void push(const T &elem) {
        lock_guard<mutex> lock(m);
        q.push(elem);
    }

    bool pop(T &elem) {
        lock_guard<mutex> lock(m);
        if(q.empt()) return false;
        elem = q.front();
        q.pop();
        return true;
    }


};
