#ifndef LIST_NODE_H_
#define LIST_NODE_H_

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {
	}
};

#endif
