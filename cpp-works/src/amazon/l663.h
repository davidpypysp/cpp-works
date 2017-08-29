#include <iostream>
#include "../leetcode_util/tree_node.h"
using namespace std;


class L663 {
public:
    bool checkEqualTree(TreeNode* root) {
        int sum = SumTree(root);
        bool exist = false;
        EqualTree(root, sum, true, exist);
        return exist;
    }
    
    long SumTree(TreeNode* root) {
        if(!root) return 0;
        return root->val + SumTree(root->left) + SumTree(root->right);
    }
    
    int EqualTree(TreeNode* root, int sum, bool root_flag, bool &exist) {
        if(!root || exist) return 0;
        int val = root->val + EqualTree(root->left, sum, false, exist) + EqualTree(root->right, sum, false, exist);
        if(!root_flag && (val << 1) == sum) exist = true;
        return val;
    }
};