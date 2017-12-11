#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int DegreeOfArray(vector<int> nums) {
    int n = nums.size();
    int degree = 0;
    int result = n;
    unordered_map<int, int> cnt;
    unordered_map<int, int> left_index;
    for(int i = 0; i < n; i++) {
        int val = nums[i];
        cnt[val]++;
        if(left_index.find(val) == left_index.end()) left_index[val] = i;
        if(cnt[val] >= degree) degree = cnt[val];
    }

    cnt.clear();
    for(int i = 0; i < n; i++) {
        int val = nums[i];
        cnt[val]++;
        if(cnt[val] == degree) {
            result = min(result, i - left_index[val] + 1);
        }
    }
    return result;

    return result;
}
