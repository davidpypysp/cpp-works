#include <iostream>
#include <vector>
using namespace std;

class L287 {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;
        do {
            fast = nums[nums[fast]];
            slow = nums[slow];
        } while(slow != fast);
        fast = 0;
        while(slow != fast) {
            fast = nums[fast];
            slow = nums[slow];
        }
        return slow;
        
    }
};