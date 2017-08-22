#include <iostream>
#include <stdio.h>
#include <unordered_map>
#include <vector>

using namespace std;

class L377 {
public:
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> map;
        return search(target, nums, map);
    }
    
    int search(int target, vector<int> &nums, unordered_map<int, int> &map) {
        if(target == 0) return 1;
        if(target < 0) return 0;
        if(map.find(target) != map.end()) return map[target];
        int result = 0;
        for(int i = 0; i < nums.size(); i++) {
            result += search(target - nums[i], nums, map);
        }
        map[target] = result;
        return result;
    }

        int combinationSum4_2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int d[target + 1];
        memset(d, 0, sizeof(d));
        
        for(int i = 1; i <= target; i++) {
            for(int num : nums) {
                if(num > i) break;
                else if(num == i) d[i]++;
                else {
                    d[i] += d[i - num];
                }
            }
        }
        return d[target];
    }
};