#include <iostream>
#include "../util/list_node.h"

ListNode NthToLast(ListNode *head, int n) {
	ListNode *p1 = head, *p2 = head;
	for (int i = 0; i < n-1; i++) {
		p1 = p1->next;
	}

	while (p1 != nullptr) {
		p1 = p1->next;
		p2 = p2->next;
	}
	return *p2;

}

