#include <iostream>
#include <string>
#include <vector>
using namespace std;

class L18 {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i < n-3; i++) {
            if(i-1 >= 0 && nums[i] == nums[i-1]) continue;
            for(int j = i+1; j < n-2; j++) {
                if(j-1 >= i+1 && nums[j] == nums[j-1]) continue;
                int l = j+1, r = n-1;
                if(nums[i] + nums[j] + nums[l] + nums[l+1] > target || nums[i] + nums[j] + nums[r] + nums[r-1] < target) continue; 
                while(l < r) {
                    int sum = nums[i] + nums[j] + nums[l] + nums[r];
                    if(sum == target) {
                        vector<int> v;
                        v.push_back(nums[i]);
                        v.push_back(nums[j]);
                        v.push_back(nums[l]);
                        v.push_back(nums[r]);
                        result.push_back(v);
                        while(l+1 < n && nums[l+1] == nums[l]) l++;
                        while(r-1 >= j+1 && nums[r-1] == nums[r]) r--;
                        l++, r--;
                    }
                    else if(sum < target) l++;
                    else r--;
                }
            }
        }
        return result;
        
    }
};