#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
	unordered_map<int, int> map;
	vector<int> result;
	int n = nums.size();
	for (int i = 0; i < n; ++i) {
		int num = nums[i], num2 = target - nums[i];
		if (map.find(num2) != map.end()) {
			result.push_back(i);
			result.push_back(map[num2]);
			return result;
		}
		map[num] = i;
	}
	return result;
}