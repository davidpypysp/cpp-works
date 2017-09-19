#include <vector>
using namespace std;

class L215 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return qselect(nums, 0, nums.size()-1, nums.size() - k);
    }
    
    int qselect(vector<int> &nums, int left, int right, int k) {
        int val = nums[right];
        int index = left;
        for(int i = left; i < right; i++) {
            if(nums[i] < val) swap(nums, index++, i);
        }
        swap(nums, index, right);
        if(k == index) return nums[k];
        else if(k < index) return qselect(nums, left, index-1, k);
        else return qselect(nums, index+1, right, k);
    }
    
    void swap(vector<int> &nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
    
};