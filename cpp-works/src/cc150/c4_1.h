#include "../util/tree.h"

class C4_1 {
public:
	int max_depth, min_depth;
    bool IsBalanced(TreeNode *root) {
		if (!root) return true;
		max_depth = 0;
		min_depth = 0;
		return Dfs(root, 1);
	}

	bool Dfs(TreeNode *node, int depth) {
		if (node->left == nullptr && node->right == nullptr) { 
			if (depth > max_depth) max_depth = depth;
			if (min_depth == -1 || depth < min_depth) min_depth = depth;
			if (max_depth - min_depth > 1) return false;
			return true;
		}
		if (node->left) {
			if (Dfs(node->left, depth + 1) == false) return false;
		}
		if (node->right) {
			if (Dfs(node->right, depth + 1) == false) return false;
		}
		return true;

	}
};
