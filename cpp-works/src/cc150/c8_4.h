#include <iostream>
#include <string>
#include <vector>
using namespace std;

class C8_4 {
public:
	vector<string> GetPermutation(const string &s) {
		vector<string> result;
		if (s.size() == 0) {
			result.push_back("");
			return result;
		}
		string first = s.substr(0, 1);
		string remain = s.substr(1);
		vector<string> next_permutation = GetPermutation(remain);
		for (string p : next_permutation) {
			for (int i = 0; i <= p.size(); i++) {
				string new_p = InsertChar(p, i, first);
				result.push_back(new_p);
			}
		}
		return result;
	}

	string InsertChar(const string &s, int index, string c) {
		string left = s.substr(0, index);
		string right = s.substr(index);
		return left + c + right;
	}
};