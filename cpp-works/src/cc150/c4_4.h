#include <iostream>
#include <vector>
#include <list>
#include "../util/tree.h"
#include "../util/list_node.h"

using namespace std;

vector<list<TreeNode*>> findLevelLinkList(TreeNode *root) {
	int level = 0;
	vector<list<TreeNode*>> result;
	if (!root) return result;
	list<TreeNode*> root_list;
	root_list.push_back(root);

	while (true) {
		list<TreeNode*> next_list;
		for (list<TreeNode*>::iterator it = result[level].begin(); it != result[level].end(); it++) {
			if (!(*it)->left) next_list.push_back((*it)->left);
			if (!(*it)->right) next_list.push_back((*it)->right);
		}
		if (next_list.size() != 0) {
			result.push_back(next_list);
		}
		else break;
		level++;
	}
	return result;
}
