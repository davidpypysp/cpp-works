#include <iostream>
#include <stdio.h>
#include <unordered_map>
#include <vector>

using namespace std;

class L1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        vector<int> result;
        for(int i = 0; i < nums.size(); i++) {
            int val = target - nums[i];
            if(map.find(val) != map.end()) {
                result.push_back(map[val]);
                result.push_back(i);
                return result;
            }
            map[nums[i]] = i;
        }
        return result;
    }
};