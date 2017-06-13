#include <iostream>
#include "../util//tree.h"

class C4_6 {
	TreeNode *result = nullptr;
	TreeNode* commonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
		GetSon(root, p, q);
		return result;
	}


	int GetSon(TreeNode *root, TreeNode *p, TreeNode *q) {
		if (!root) return 0;
		int num_left = GetSon(root->left, p, q);
		if (num_left == 2) return 2;
		int num_right = GetSon(root->right, p, q);
		if (num_right == 2) return 2;
		int num_mid = (root == p || root == q) ? 1 : 0;
		int num = num_left + num_right + num_mid;
		if (num == 2) {
			result = root;
		}
		return num;
	}
};
