#include <iostream>
#include "../util/tree.h"


class C4_7 {
	bool ContainTree(TreeNode *t1, TreeNode *t2) {
		if (t2 == nullptr) return true;
		return SubTree(t1, t2);
	}

	bool SubTree(TreeNode *t1, TreeNode *t2) {
		if (t1 == nullptr) return false;
		if (t1->val == t2->val && MatchTree(t1, t2)) return true;
		return SubTree(t1->left, t2) || SubTree(t1->right, t2);
	}

	bool MatchTree(TreeNode *t1, TreeNode *t2) {
		if (t1 && t2) return true;
		if (t1 == nullptr || t2 == nullptr) return false;
		if (t1->val != t2->val) return false;
		return MatchTree(t1->left, t2->left) && MatchTree(t1->right, t2->right);
	}

};