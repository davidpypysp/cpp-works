#include <vector>
#include <string>
#include <unordered_set>

using namespace std;


class L140 {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<string> result;
        if(n == 0) return result;
        vector<vector<string>> words_list(n);
        unordered_set<string> word_set;
        for(string word : wordDict) {
            word_set.insert(word);
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                string word = s.substr(i, j-i+1);
                if(word_set.find(word) != word_set.end()) {
                    words_list[i].push_back(word);
                }
            }
        }
        
        dfs(words_list, 0, n, "", result);
        return result;
        
    }
    
    void dfs(vector<vector<string>> &words_list, int index, int n, string pre, vector<string> &result) {
        if(index == n) {
            result.push_back(pre);
            return;
        }
        
        for(string word : words_list[index]) {
            string next = pre;
            if(pre == "") next += word;
            else next += " " + word;
            dfs(words_list, index + word.size(), n, next, result);
        }
    }
};