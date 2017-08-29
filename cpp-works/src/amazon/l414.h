#include <iostream>
#include <vector>
using namespace std;

class L414 {
public:
    int thirdMax(vector<int>& nums) {
        long max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
        bool flag2 = false, flag3 = false;
        for(int num : nums) {
            if(num > max1) max1 = num;
        }
        for(int num : nums) {
            if(num != max1) {
                flag2 |= true;
                if(num > max2) max2 = num;
            }
        }
        for(int num : nums) {
            if(num != max1 && num != max2 && flag2) {
                flag3 |= true;
                if(num > max3) max3 = num;
            }
        }
        return flag3 ? max3 : max1;
    }
};