#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class L645 {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int duplicate = -1, miss = -1;
        for(int val : nums) {
            if(nums[abs(val) - 1] > 0) {
                nums[abs(val) - 1] *= -1;
            }
            else {
                duplicate = abs(val);
            }
        }
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > 0) {
                miss = i+1;
                break;
            }
        }
        vector<int> result = {duplicate, miss};
        return result;
    }
};