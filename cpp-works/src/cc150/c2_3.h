#include <iostream>
#include "../util/list_node.h"



// copy next node's data to current node, then delete next node;
// It doesn't work for the last node
bool deleteNode(ListNode *node) {
	if (node == nullptr || node->next == nullptr) return false;
	ListNode *next_node = node->next;
	node->val = next_node->val;
	node->next = next_node->next;
	return true;
}