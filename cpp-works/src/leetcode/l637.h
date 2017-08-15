#include <iostream>
#include <stdio.h>

#include "../leetcode_util/tree_node.h"
#include <vector>
#include <queue>

using namespace std;

class L637 {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> list;
        if(!root) return list;
        int num = 1;
        int cnt = 0;
        long sum = 0;
        int next_num = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(q.empty() == false) {
            TreeNode *node = q.front();
            q.pop();
            cnt++;
            sum += node->val;
            if(node->left) {
                q.push(node->left);
                next_num++;
            }
            if(node->right) {
                q.push(node->right);
                next_num++;
            }
            if(cnt == num) {
                list.push_back((double)sum / (double)num);
                num = next_num;
                cnt = 0;
                sum = 0;
                next_num = 0;
            }

        }
        return list;
    }


    
};