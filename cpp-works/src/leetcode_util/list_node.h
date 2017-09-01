#ifndef LIST_NODE_H_
#define LIST_NODE_H_

#include <stdlib.h>
#include <iostream>


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

#endif