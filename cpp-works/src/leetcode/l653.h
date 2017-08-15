#include <iostream>
#include <stdlib.h>
#include <string>
#include <unordered_set>
#include <queue>
#include <vector>
#include <stack>

#include "../leetcode_util/tree_node.h"

using namespace std;

struct BSTIterator {
    stack<TreeNode*> st;
    TreeNode* root;
    TreeNode* cur;
    bool asc;

    BSTIterator(TreeNode* node, bool asc) : root(node), cur(node), asc(asc) {
    }

    TreeNode* Next() {
        while(cur || !st.empty()) {
            if(cur) {
                st.push(cur);
                cur = asc ? cur->left : cur->right;
            }
            else {
                TreeNode *res = st.top();
                st.pop();
                cur = asc ? res->right : res->left;
                return res;
            }
        }
        return nullptr;


    }

};


class L653 {
public:
    bool FindTarget1(TreeNode* root, int k) {
        if(!root) return false;
        unordered_set<int> set;
        return Find1(root, k, set);
    }

    bool Find1(TreeNode* root, int k, unordered_set<int> &set) {
        if(!root) return false;
        if(set.find(k - root->val) != set.end()) return true;
        set.insert(root->val);
        return Find1(root->left, k, set) || Find1(root->right, k, set);
    }

    bool FindTarget2(TreeNode* root, int k) {
        if(!root) return false;
        unordered_set<int> set;
        queue<TreeNode*> q;
        q.push(root);
        while(q.empty() == false) {
            TreeNode* node = q.front();
            q.pop();
            if(set.find(k - node->val) != set.end()) return true;
            set.insert(node->val);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        return false;
    }

    bool FindTarget3(TreeNode* root, int k) {
        if(!root) return false;
        vector<int> list;
        Search(root, list);

        int l = 0, r = list.size() - 1;

        while(l < r) {
            int sum = list[l] + list[r];
            if(sum == k) return true;
            else if(sum > k) r--;
            else if(sum < k) l++;
        }
        return false;

    }

    void Search(TreeNode* root, vector<int> &list) {
        if(!root) return;
        Search(root->left, list);
        list.push_back(root->val);
        Search(root->right, list);
    }

    bool FindTarget4(TreeNode* root, int k) {
        BSTIterator l(root, true);
        BSTIterator r(root, false);

        int left_val = l.Next()->val, right_val = r.Next()->val;

        while(left_val < right_val) {
            int sum = left_val + right_val;
            if(sum == k) return true;
            else if(sum > k) right_val = r.Next()->val;
            else left_val = l.Next()->val;
        }
        return false;


    }


};
