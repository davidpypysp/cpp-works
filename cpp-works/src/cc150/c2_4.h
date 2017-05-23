#include <iostream>
#include "../util/list_node.h"

using namespace std;

ListNode* addList(ListNode *l1, ListNode *l2, int carry) {
	if (!l1 && !l2) return nullptr;
	ListNode *node = new ListNode(0);
	int val = 0;
	if (l1) val += l1->val;
	if (l2) val += l2->val;
	node->val = val % 10;
	node->next = addList(l1 ? l1->next : nullptr, l2 ? l2->next : nullptr, val / 10);
	return node;
}