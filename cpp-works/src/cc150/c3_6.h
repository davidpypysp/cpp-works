#include <iostream>
#include <stack>

using namespace std;

stack<int> SortStack(stack<int> s) {
	stack<int> r;
	while (!s.empty()) {
		int val = s.top();
		s.pop();
		while (!r.empty() || r.top() < val) {
			s.push(r.top());
			r.pop();
		}
		r.push(val);
	}
	return r;
}