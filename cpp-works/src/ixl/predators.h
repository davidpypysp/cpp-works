#include <iostream>
#include <vector>
using namespace std;

int dfs(vector<int> &nums, vector<int> &cnts, int index) {
    if(cnts[index] != 0) return cnts[index];
    if(nums[index] == -1) {
        cnts[index] = 1;
    }
    else {
        cnts[index] = 1 + dfs(nums, cnts, nums[index]);
    }
    return cnts[index];
}


int MaximumGroup(vector<int> nums) {
    int n = nums.size();
    if(n == 0) return 0;
    int result = 0;
    vector<int> cnts(n, 0);
    for(int i = 0; i < nums.size(); i++) {
        if(cnts[i] == 0) {
            int cnt = dfs(nums, cnts, i);
            result = max(result, cnt);
        }
    }
    return result;
}