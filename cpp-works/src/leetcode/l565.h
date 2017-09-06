#include <iostream>
#include <vector>
using namespace std;

class L565 {
public:
    int arrayNesting(vector<int>& nums) {
        int max_val = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == -1) continue;
            int len = 0;
            int val = nums[i];
            while(nums[val] >= 0) {
                int next = nums[val];
                nums[val] = -1;
                val = next;
                len++;
            }
            max_val = max(max_val, len);
        }
        return max_val;
    }
};