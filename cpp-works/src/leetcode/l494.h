#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;


class L494 {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        return dfs(nums, 0, 0, S);
    }
    
    int dfs(vector<int>& nums, int cnt, int sum, int target) {
        if(cnt == nums.size()) {
            if(sum == target) return 1;
            else return 0;
        }
        int result = 0;
        result += dfs(nums, cnt+1, sum+nums[cnt], target);
        result += dfs(nums, cnt+1, sum-nums[cnt], target);
        return result;
    }
    
};
