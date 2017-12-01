#include <iostream>
#include <mutex>
using namespace std;


class CircleQueue {
public: 
    CircleQueue(int size) {
        this->size = size;
        my_queue = new int[size];
        head = 0;
        tail = -1;
        cnt = 0;
    }

    bool enqueue(int x) {
        bool result = true;
        m.lock();
        if(cnt == size) {
            result = false;
        }
        else {
            my_queue[(++tail) % size] = x;
            cnt++;
        }
        m.unlock();
        return result;
    }

    int dequeue() {
        int result = 0;
        m.lock();
        if(cnt == 0) {
            m.unlock();
            throw("empty error");
        }
        else {
            result = my_queue[(++head) % size];
            cnt--;
        }
        m.unlock();

        return result;
    }

    virtual ~CircleQueue() {
        delete[] my_queue;
        my_queue = nullptr;
    }

private: 
    int *my_queue;
    int size;
    int head, tail;
    int cnt;
    mutex m;
};