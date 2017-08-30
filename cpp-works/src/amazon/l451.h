#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class L451 {
public:
    string frequencySort(string s) {
        int n = s.size();
        unordered_map<char, int> map;
        for(char c : s) map[c]++;
        vector<char> cnts[n+1];
        
        for(auto &p : map) cnts[p.second].push_back(p.first);
        string result = "";
        for(int i = n; i > 0; i--) {
            if(cnts[i].size() == 0) continue;
            for(char c : cnts[i]) {
                for(int j = 0; j < i; j++) result.push_back(c);
            }
        }
        return result;
    }
};