#include <string>
#include <iostream>
#include "../leetcode_util/tree_node.h"
using namespace std;


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class L297 {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "#";
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int start = 0;
        return dfs(data, start);
        
    }
    
    TreeNode* dfs(string data, int &cnt) {
        string str = "";
        for(; cnt < data.size() && data[cnt] != ','; cnt++) {
            str+=data[cnt];
        }
        if(cnt < data.size() && data[cnt] == ',') cnt++;
        if(str == "#") {
            return nullptr;
        }
        int val = stoi(str);
        TreeNode *node = new TreeNode(val);
        node->left = dfs(data, cnt);
        node->right = dfs(data, cnt);
        return node;
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));