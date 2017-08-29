#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;


class L228 {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        if(nums.size() == 0) return result;
        if(nums.size() == 1) {
            result.push_back(to_string(nums[0]));
            return result;
        }
        int left = 0;
        for(int i = 1; i <= nums.size(); i++) {
            if(i == nums.size() || (long)(nums[i] - nums[i-1]) > 1) {
                if(i - 1 == left) {
                    result.push_back(to_string(nums[left]));
                }
                else {
                    result.push_back(to_string(nums[left]) + "->" + to_string(nums[i-1]));
                }
                left = i;
            }
        }
        return result;
    }
};