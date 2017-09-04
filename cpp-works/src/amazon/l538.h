#include <iostream>
#include "../leetcode_util/tree_node.h"

class L538 {
public:
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        dfs(root, sum);
        return root;
    }
    
    void dfs(TreeNode *node, int &sum) {
        if(!node) return; 
        dfs(node->right, sum);
        node->val += sum;
        sum = node->val;
        dfs(node->left, sum);
    }
};