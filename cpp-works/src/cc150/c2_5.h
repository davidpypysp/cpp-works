#include <iostream>
#include "../util/list_node.h"


ListNode* FindBegining(ListNode *head) {
	ListNode* l1 = head;
	ListNode* l2 = head;

	do {
		l1 = l1->next;
		l2 = l2->next->next;
	} while (l1 != l2);

	l1 = head;

	while (l1 != l2) {
		l1 = l1->next;
		l2 = l2->next;
	}
	return l1;
}
