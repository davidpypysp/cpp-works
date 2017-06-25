#include <iostream>
#include <vector>

using namespace std;


class C8_3 {
public:
	vector<vector<int>> all_subsets;
	vector<vector<int>> GetSubset(vector<int> set) {
		vector<int> prev;
		GetSubset(set, prev, 0);
		return all_subsets;
	}

	void GetSubset(vector<int> set, vector<int> prev, int left) {
		
		for (int i = left; i < set.size(); i++) {
			vector<int> new_prev(prev);
			new_prev.push_back(set[i]);
			GetSubset(set, new_prev, i + 1);
		}
		all_subsets.push_back(prev);

	}
};
