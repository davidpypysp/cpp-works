#include <iostream>
#include "../util/tree.h"

using namespace std;


TreeNode* inorderSucc(TreeNode *e) {
	if (!e) return nullptr;
	if (!e->parent || e->right) return e->right;
	TreeNode *p;
	while ((p = e->parent) != nullptr) {
		if (e == p->left) return p;
		e = p;
	}
	return nullptr;
}
