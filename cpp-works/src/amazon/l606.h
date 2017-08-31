#include <iostream>
#include <string>
#include "../leetcode_util/tree_node.h"
using namespace std;

class Solution {
public:
    string tree2str(TreeNode* t) {
        return dfs(t);
    }
    
    string dfs(TreeNode *node) {
        if(!node) return "";
        string s = to_string(node->val);
        if(!node->left && !node->right) return s;
        s.append("(" + dfs(node->left) + ")");
        if(node->right) s.append("(" + dfs(node->right) + ")");
        return s;
    }
};