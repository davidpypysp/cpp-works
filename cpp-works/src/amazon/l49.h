#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


class L49 {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, int> map;
        int cnt = 0;
        for(int i = 0; i < strs.size(); i++) {
            string s = strs[i];
            string t = s;
            sort(t.begin(), t.end());
            if(map.find(t) == map.end()) {
                map[t] = cnt;
                vector<string> v;
                v.push_back(s);
                result.push_back(v);
                cnt++;
            }
            else {
                result[map[t]].push_back(s);
            }
        }
        return result;
    }        
};