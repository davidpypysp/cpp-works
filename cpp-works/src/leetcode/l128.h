#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class L128 {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set, vis;
        for(int num : nums) {
            set.insert(num);
        }
        
        int result = 0;
        for(int num : set) {
            if(vis.find(num) == vis.end()) {
                vis.insert(num);
                int left = num, right = num;
                while(set.find(left-1) != set.end()) {
                    vis.insert(--left);
                }
                while(set.find(right+1) != set.end()) {
                    vis.insert(++right);
                }
                result = max(result, right-left + 1);
            }
        }
        return result;
    }
};