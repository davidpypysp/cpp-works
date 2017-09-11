#include <iostream>
#include <vector>
#include <deque>
using namespace std;


class L239 {
public:    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> result;
        for(int i = 0; i < nums.size(); i++) {
            if(!q.empty() && q.front() <= i-k) q.pop_front();
            while(!q.empty() && nums[i] >= nums[q.back()]) q.pop_back();
            q.push_back(i);
            if(i >= k-1) result.push_back(nums[q.front()]);
        }
        return result;
    }
};