#include <iostream>
#include <string>
#include <vector>
using namespace std;

class L17 {
public:
    string map[10] = {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };
    
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if(digits.size() == 0) return result;
        dfs(digits, 0, "", result);
        return result;
    }
    
    void dfs(string &digits, int index, string pre, vector<string> &result) {
        if(index == digits.size()) {
            result.push_back(pre);
            return;
        }
        
        for(char c : map[digits[index] - '0']) 
            dfs(digits, index+1, pre + c, result);
    }
};