#include <iostream>
#include <string>
#include "../leetcode_util/tree_node.h"

using namespace std;


class L536 {
public:
    TreeNode* str2tree(string s) {
        if(s.size() == 0) return nullptr;
        int index = 0;
        return dfs(s, index);
    }
    
    TreeNode* dfs(string s, int &index) {
        string str = "";
        for(; index < s.size() && s[index] != '(' && s[index] != ')'; index++) {
            str.push_back(s[index]);
        }
        int val = stoi(str);
        TreeNode *node = new TreeNode(val);
        if(index < s.size() && s[index] == '(') {
            node->left = dfs(s, ++index);
            ++index;
            if(index < s.size() && s[index] == '(') {
                node->right = dfs(s, ++index);
                ++index;
            }
        }
        return node;
    }
};