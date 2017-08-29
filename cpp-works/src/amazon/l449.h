 
#include <iostream>
#include <string>
#include "../leetcode_util/tree_node.h"
using namespace std;
class L449 {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string s = to_string(root->val);
        if(root->left) s += "," + serialize(root->left);
        if(root->right) s += "," + serialize(root->right);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return nullptr;
        int cnt = 0;
        return dfs(data, cnt, INT_MIN, INT_MAX);
    }
    
    TreeNode* dfs(string &data, int &cnt, int min_val, int max_val) {
        if(cnt == data.size()) return nullptr;
        string str = "";
        int i = cnt;
        for(; i < data.size() && data[i] != ','; i++) {
            str.push_back(data[i]);
        }
        int val = stoi(str);
        if(val >= min_val && val <= max_val) {
            cnt = i;
            if(cnt < data.size() && data[cnt] == ',') cnt++;
            TreeNode* node = new TreeNode(val);
            node->left = dfs(data, cnt, min_val, val);
            node->right = dfs(data, cnt, val, max_val);
            return node;
        }
        return nullptr;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));