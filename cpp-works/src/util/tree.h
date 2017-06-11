#ifndef TREE_H_
#define TREE_H_

class TreeNode {
public:
	int val;
	TreeNode *left, *right, *parent;
	TreeNode(int val = 0) {
		this->val = val;
		left = nullptr;
		right = nullptr;
	}
};


#endif // TREE_H_