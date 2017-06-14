#include <iostream>
#include "../util/tree.h"
#include <vector>

using namespace std;

class C4_8 {
	void FindSUmBinaryTree(TreeNode *root, int sum) {
		vector<int> vec;
		FindSum(root, sum, vec, 0);
	}
	void FindSum(TreeNode *root, int sum, vector<int> &vec, int level) {
		if (!root) return;
		vec.push_back(root->val);

		int tmp = sum;
		for (int i = level; i >= 0; i--) {
			tmp -= vec[i];
			if (tmp == 0) {
				PrintVec(vec, i, level);
			}
		}

		vector<int> vl = vec;
		vector<int> vr = vec;
		FindSum(root->left, sum, vl, level + 1);
		FindSum(root->right, sum, vr, level + 1);
	}

	void PrintVec(vector<int> &vec, int l, int r) {
		for (int i = l; i <= r; i++) {
			cout << vec[i] << " ";
		}
		cout << endl;
	}
};