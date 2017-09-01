#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

class L41 {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[i] <= 0) nums[i] = n+1;
        }
        
        for(int i = 0; i < n; i++) {
            int val = abs(nums[i]);
            if(val > 0 && val <= n) {
                if(nums[val-1] > 0) nums[val-1] *= -1;
            }
        }
        
        for(int i = 0; i < n; i++) {
            if(nums[i] > 0) return i+1;
        }
        return n+1;
        
    }
};