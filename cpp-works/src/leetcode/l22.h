#include <iostream>
#include <vector>
using namespace std;

class L22 {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        dfs("", n, n, result);
        return result;
    }
    
    void dfs(string pre, int left, int right, vector<string> &result) {
        if(left == 0 && right == 0) {
            result.push_back(pre);
            return;
        }
        if(left > 0) dfs(pre + '(', left-1, right, result);
        if(right > left) dfs(pre + ')', left, right-1, result);
    }
    
    
};