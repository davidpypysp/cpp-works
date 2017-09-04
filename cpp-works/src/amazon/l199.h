#include <iostream>
#include <vector>
#include "../leetcode_util/tree_node.h"

using namespace std;

class L199 {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        dfs(root, 1, result);
        return result;
    }
    
    void dfs(TreeNode* node, int level, vector<int> &result) {
        if(!node) return;
        if(result.size() < level) result.push_back(node->val);
        else result[level-1] = node->val;
        dfs(node->left, level+1, result);
        dfs(node->right, level+1, result);
    }
    
};