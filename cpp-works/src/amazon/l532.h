#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;


class L532 {
public:
    int findPairs(vector<int>& nums, int k) {
        int result = 0;
        unordered_map<int, int> hash;
        
        if(k == 0) {
            for(int i = 0; i < nums.size(); i++) {
                if(hash.find(nums[i]) != hash.end()) {
                    if(hash[nums[i]] == 1) result++;
                }
                else hash[nums[i]] = 0;
                hash[nums[i]]++;
            }
            return result;
        }
        if(k < 0) return 0;
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < nums.size(); i++) {
            if(i+1 < nums.size() && nums[i] == nums[i+1]) continue;
            if(hash.find(nums[i]) == hash.end()) {
                if(hash.find(nums[i] + k) != hash.end()) {
                    result += hash[nums[i] + k];
                }
                if(hash.find(nums[i] - k) != hash.end()) {
                    result += hash[nums[i] - k];
                }
                hash[nums[i]] = 0;
            }
            
            hash[nums[i]]++;
        }
        return result;
    }
};