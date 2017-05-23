#include <iostream>
#include "../util/list_node.h"
#include <stack>

using namespace std;

class NodeWithMin {
public:
	int val;
	int min;

	NodeWithMin(int val) {
		this->val = val;
	}
};

class StakeWithMin {
	stack<NodeWithMin> st;

	bool IsEmpty() {
		return st.empty();
	}

	void Push(int val) {
		NodeWithMin node(val);
		if (st.empty() || st.top().min > val) {
			node.min = val;
		}
		else {
			node.min = st.top().min;
		}
		st.push(node);
	}

	void Pop() {
		return st.pop();
	}

};
