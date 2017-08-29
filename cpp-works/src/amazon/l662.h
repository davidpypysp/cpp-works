
 #include <iostream>
 #include <queue>
 #include "../leetcode_util/tree_node.h"
using namespace std;


struct NodeInfo {
    TreeNode* node;
    int level;
    int index;
    NodeInfo(TreeNode* node, int level, int index) : node(node), level(level), index(index) {}
};


class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int result = 0;
        queue<NodeInfo> q;
        q.push(NodeInfo(root, 0, 1));
        int level = -1;
        int left = -1, right = -1;
        while(q.empty() == false) {
            NodeInfo node_info = q.front();
            q.pop();
            if(node_info.level > level) {
                level = node_info.level;
                left = node_info.index;
                
            }
            result = max(result, node_info.index - left + 1);
            if(node_info.node->left) q.push(NodeInfo(node_info.node->left, level+1, node_info.index << 2));
            if(node_info.node->right) q.push(NodeInfo(node_info.node->right, level+1, (node_info.index << 2) + 1));
            
        }
        return result;
    }
};