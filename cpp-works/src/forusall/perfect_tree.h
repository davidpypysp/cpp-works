#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

struct Node {
    Node *left, *right;
    int val;
    Node(int val) : val(val) {
        left = right = nullptr;
    }
};


int dfs(Node *root, int level) { // return min level;
    if(root->left == nullptr || root->right == nullptr) {
        return level;
    }
    return min(dfs(root->left, level+1), dfs(root->right, level+1));
}

int dfs(Node *root) {
    if(!root) return 0;
    return 1 + min(dfs(root->left), dfs(root->right));
}

int get_perfect(Node *root) {
    if(!root) return 0;
    int level =  dfs(root->left, 1);
    return (1 << level) - 1;
}


