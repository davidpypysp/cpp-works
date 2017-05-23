#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class SetOfStacks {
	vector<stack<int>> stacks;
	int threshold;

	SetOfStacks(int threshold = 3) : threshold(threshold) {
	}

	void Push(int val) {
		if (stacks.empty() || stacks.back().size == threshold) {
			stack<int> st;
			st.push(val);
			stacks.push_back(st);
		}
		else {
			stacks.back().push(val);
		}
	}

	void Pop(int val) {
		if (stacks.empty()) return;

		if (stacks.back().empty()) {
			stacks.pop_back();
		}
		stacks.back().pop();

	}

};



