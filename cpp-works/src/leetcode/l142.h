#include <iostream>
#include "../leetcode_util/list_node.h"
using namespace std;

class L142 {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head) return nullptr;
        ListNode *slow = head, *fast = head;
        while(fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
            if(slow == fast) {
                slow = head;
                while(slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};