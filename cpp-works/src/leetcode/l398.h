#include <iostream>
#include <vector>
using namespace std;

class L398 {
public:
    vector<int> nums;
    L398(vector<int> nums) : nums(nums){
    }
    
    int pick(int target) {
        int cnt = 0;
        int result = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == target) {
                int rnd = rand() % (++cnt);
                if(rnd == 0) result = i;
            }
        }
        return result;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */