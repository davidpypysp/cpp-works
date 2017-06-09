#include <stdio.h>
#include "../util/tree.h"


class SortedArrayToTree {
public:

	TreeNode* CreatMinimalBST(int array[], int size) {
		return AddToTree(array, 0, size);
	}

	TreeNode* AddToTree(int arr[], int start, int end) {
		if (start >= end) return nullptr;
		int mid = (start + end) / 2;
		TreeNode *node = new TreeNode(arr[mid]);
		node->left = AddToTree(arr, start, mid);
		node->right = AddToTree(arr, mid+1, end);
	}


};