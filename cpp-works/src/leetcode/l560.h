#include <vector>
#include <unordered_map>
using namespace std;

class L560 {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        map[0] = 1;
        int sum = 0, result = 0;
        for(int &num : nums) {
            sum += num;
            result += map[sum-k];
            map[sum]++;
        }
        return result;
        
    }
};