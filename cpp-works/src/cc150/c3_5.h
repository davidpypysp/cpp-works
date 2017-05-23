#include <iostream>
#include <stack>

using namespace std;

template <typename T>
class MyQueue {
public:
	stack<T> st1, st2;

	MyQueue() {
	}

	void Push(const T &a) {
		st1.push(a);
	}

	T Pop() {
		if (st2.empty()) {
			while (!st1.empty()) {
				st1.push(st1.pop());
			}
		}
		return st2.pop();
	}

};