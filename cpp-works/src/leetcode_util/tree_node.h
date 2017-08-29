#ifndef TREE_NODE_H_
#define TREE_NODE_H_

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {

    }
};

#endif