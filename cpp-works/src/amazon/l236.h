#include <iostream>
#include "../leetcode_util/tree_node.h"
using namespace std;

class L236 {
public:
    TreeNode* result;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        result = nullptr;
        dfs(root, p, q);
        return result;
    }
    
    int dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return 0;
        int left, right;
        if((left = dfs(root->left, p, q)) == 2) return 2;
        if((right = dfs(root->right, p, q)) == 2) return 2;
        int sum = left + right + ((root == p || root == q) ? 1 : 0);
        if(sum == 2) result = root;
        return sum;
    }
    
};