#include <iostream>
#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <queue>
#include <map>
#include "../leetcode_util/tree_node.h"

using namespace std;

struct NodeInfo {
    TreeNode *node;
    int pos;
    NodeInfo(TreeNode *node, int pos) : node(node), pos(pos) {}
};

class L314 {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root) return result;
        
        unordered_map<int, vector<int>> map;
        int left_max = 0, right_max = 0;
        
        queue<NodeInfo*> q;
        NodeInfo *root_info = new NodeInfo(root, 0);
        q.push(root_info);
        
        while(!q.empty()) {
            NodeInfo *node_info = q.front();
            q.pop();
            
            TreeNode *node = node_info->node;
            int pos = node_info->pos;
            
            if(pos < 0) left_max = (pos < left_max) ? pos : left_max;
            else right_max = (pos > right_max) ? pos : right_max;
            
            if(map.find(pos) == map.end()) {
                vector<int> vec;
                map[pos] = vec;
            }
            map[pos].push_back(node->val);
            
            if(node->left) {
                NodeInfo *left = new NodeInfo(node->left, pos-1);
                q.push(left);
            }
            if(node->right) {
                NodeInfo *right = new NodeInfo(node->right, pos+1);
                q.push(right);
            }
            
        }
        
        
        
        for(int i = left_max; i <= right_max; i++) {
            result.push_back(map[i]);
        }
        return result;
    }

    vector<vector<int>> verticalOrder2(TreeNode* root) {
        vector<vector<int>> result;
        if(!root) return result;
        map<int, vector<int>> treemap;
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 0));
        int min = 0, max = 0;
        
        while(!q.empty()) {
            TreeNode* node = q.front().first;
            int pos = q.front().second;
            q.pop();
            
            if(pos < min) min = pos;
            else if(pos > max) max = pos;
            
            if(treemap.find(pos) == treemap.end()) {
                vector<int> v;
                treemap[pos] = v;
            }
            treemap[pos].push_back(node->val);
            
            if(node->left) {
                q.push(make_pair(node->left, pos-1));
            }
            if(node->right) {
                q.push(make_pair(node->right, pos+1));
            }
        }
        
        for(auto &v : treemap) {
            result.push_back(v.second);
        }
        return result;
        
    }

};
