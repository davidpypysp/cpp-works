#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class L347 {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> map;
        for(int num : nums) {
            map[num]++;
        }
        vector<int> cnts[n+1];
        for(auto &p : map) {
            cnts[p.second].push_back(p.first);
        }
        vector<int> result;
        for(int i = n; i > 0; i--) {
            if(cnts[i].size() == 0) continue;
            for(int num : cnts[i]) {
                result.push_back(num);
                k--;
                if(k == 0) return result;
            }
        }
        return result;
        
    }
};