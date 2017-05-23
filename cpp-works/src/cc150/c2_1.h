#include <iostream>
#include <unordered_map>
#include "../util/list_node.h"

using namespace std;

// with buffer
void deleteDups(ListNode *node) {
	ListNode *cur = node;
	ListNode *prev = nullptr;

	unordered_map<int, bool> map;

	while (cur != nullptr) {
		if (map.find(cur->val) == map.end()) {
			map[cur->val] = true;
			prev = cur;
		}
		else {
			prev->next = cur->next;
		}

		cur = cur->next;
	}

}


void deleteDups2(ListNode *node) {
	ListNode *cur = node;
	ListNode *prev = nullptr;
	while (cur != nullptr) {
		bool dup_flag = false;
		for (ListNode *k = node; k != cur; k = k->next) {
			if (k->val == cur->val) {
				prev->next = cur->next;
				dup_flag = true;
				break;
			}
		}

		if (!dup_flag) {
			prev = cur;
		}
		cur = cur->next;
	}
}
