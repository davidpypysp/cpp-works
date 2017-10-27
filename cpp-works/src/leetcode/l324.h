#include <vector>
using namespace std;

class L324 {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        float mid = 0;
        if(n % 2 == 0) {
            mid = (qselect(nums, 0, n-1, n / 2 - 1) + qselect(nums, 0, n-1, n / 2)) / 2.0; 
        }
        else {
            mid = qselect(nums, 0, n-1, n / 2);
        }
        
        int even = 0, odd = 1;
        while(even < n && odd < n) {
            if(nums[even] >= mid) {
                swap(nums[even], nums[odd]);
                odd += 2;
            }
            else {
                even += 2;
            }
        }
        
    }
    
    int qselect(vector<int> &nums, int l, int r, int k) {
        int left = l, val = nums[r];
        for(int i = l; i < r; i++) {
            if(nums[i] < val) swap(nums[i], nums[left++]);
        }
        swap(nums[left], nums[r]);
        if(left == k) return nums[k];
        else if(k < left) return qselect(nums, l, left-1, k);
        else return qselect(nums, left+1, r, k);
    }
    
};