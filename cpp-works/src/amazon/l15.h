#include <iostream>
#include <vector>
using namespace std;

class L15 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        if(nums.size() == 0) return result;
        
        std::sort(nums.begin(), nums.end());
        
        for(int i = 0; i < n-2; i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int l = 0, r = nums.size() - 1;
            while(l < r) {
                if((l == i) || (l+1 < nums.size() && nums[l] == nums[l+1])) {
                    l++;
                    continue;
                }
                if((r == i) || (r-1 >= 0 && nums[r] == nums[r-1])) {
                    r--;
                    continue;
                }
                
                int sum = nums[i] + nums[l] + nums[r];
                if(sum == 0) {
                    vector<int> tri;
                    tri.push_back(i);
                    tri.push_back(l);
                    tri.push_back(r);
                    result.push_back(tri);
                    l++;
                    r--;
                }
                else if(sum < 0) l++;
                else r--;
                
            }
        }
        return result;
        
    }
};