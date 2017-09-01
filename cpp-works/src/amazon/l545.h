#include <iostream>
#include <vector>
#include "../leetcode_util/tree_node.h"
using namespace  std;


class L545 {
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> result;
        if(!root) return result;
        dfs(root, result, true, true, true);
        return result;
    }
    
    void dfs(TreeNode* node, vector<int> &result, bool lb, bool rb, bool rt) {
        if(rt) {
            result.push_back(node->val);
            if(node->left) {
                dfs(node->left, result, true, false, false);
            }
            if(node->right) {
                dfs(node->right, result, false, true, false);
            }
            return;
        }
        else {
            if(lb) result.push_back(node->val);
            if(!lb && !rb && !node->left && !node->right) result.push_back(node->val);
            if(node->left) {
                if(rb && !node->right) dfs(node->left, result, false, true, false);
                else dfs(node->left, result, lb, false, false);
            }
            if(node->right) {
                if(lb && !node->left) dfs(node->right, result, true, false, false);
                else dfs(node->right, result, false, rb, false);
            }
            if(rb) result.push_back(node->val);
            
        }
        
        
    }
};