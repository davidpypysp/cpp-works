#include <iostream>
#include <stdio.h>
#include "../leetcode_util/tree_node.h"
#include <queue>

using namespace std;


class L572 {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(!s || !t) return false;
        queue<TreeNode*> q;
        q.push(s);
        while(!q.empty()) {
            TreeNode *node = q.front();
            q.pop();
            if(isEqual(node, t)) return true;
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
            
        }
        return false;
    }
    
    bool isEqual(TreeNode *s, TreeNode* t) {
        if(s == nullptr && t == nullptr) return true;
        if(s == nullptr || t == nullptr) return false;
        if(s->val != t->val) return false;
        return isEqual(s->left, t->left) && isEqual(s->right, t->right);
    }

    bool isSubtree2(TreeNode* s, TreeNode* t) {
        string str_s = "", str_t = "";
        TreeString(s, str_s);
        TreeString(t, str_t);

        return KMP(str_t, str_s);
    }

    vector<int> preKMP(string substr) {
        int m = substr.size();
        vector<int> f(m);        
        int k;
        f[0] = -1;
        for (int i = 1; i < m; i++) {
            k = f[i - 1];
            while (k >= 0) {
                if (substr[k] == substr[i - 1])
                    break;
                else
                    k = f[k];
            }
            f[i] = k + 1;
        }
        return f;
    }
 
    bool KMP(string substr, string str) {
        int m = substr.size();
        int n = str.size();
        vector<int> f;
        f = preKMP(substr);     
        int i = 0;
        int k = 0;        
        while (i < n) {
            if (k == -1) {
                i++;
                k = 0;
            }
            else if (str[i] == substr[k]) {
                i++;
                k++;
                if (k == m) {
                    return true;
                }
            }
            else {
                k = f[k];
            }
        }
        return false;
    }

    void TreeString(TreeNode* root, string &s) {
        if(!root) return;
        s += '[';
        s += '(' + to_string(root->val) + ')';
        TreeString(root->left, s);
        TreeString(root->right, s);
        s += ']';
    }


};