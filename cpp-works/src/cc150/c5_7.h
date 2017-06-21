#include <iostream>
#include <string>
#include <vector>

using namespace std;


class C5_7 {
public:
	int FindMissing(int arr[], int n) {
		vector<int> vec;
		for (int i = 0; i < n; i++) vec.push_back(arr[i]);
		return FindMissing(vec, n, 0);
	}

	int FindMissing(vector<int> vec, int n, int index) {
		if (vec.size() == 0) return 0;
		int k = 1 << index;
		vector<int> odd_vec, even_vec;
		for (int x : vec) {
			if (x & (1 << index)) {
				odd_vec.push_back(x);
			}
			else {
				even_vec.push_back(x);
			}
		}
		int result = 0;
		if (odd_vec.size() < even_vec.size()) { // 1 removed
			result = (FindMissing(odd_vec, n, index + 1) << 1) + 1;
		}
		else {
			result = FindMissing(even_vec, n, index + 1) << 1;
		}
		return result;

	}
};
