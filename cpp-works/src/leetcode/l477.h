#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

class L477 {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size();
        int cnt[32];
        memset(cnt, 0, sizeof(cnt));
        int result = 0;
        for(int pos = 0; pos < 32; pos++) {
            int cnt = 0;
            for(int num : nums) {
                cnt += ((num >> pos) & 1);
            }
            result += cnt * (n - cnt);
        }
        
        return result;
    }
};
