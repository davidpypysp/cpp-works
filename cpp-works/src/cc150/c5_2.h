#include <iostream>
#include <string>

using namespace std;


class C5_2 {
public:
	string DecToBin(const string &n) {
		int dot_index = n.find(".");
		string left = n.substr(0, dot_index);
		string right = n.substr(dot_index + 1, n.size() - dot_index);
		int int_part = stoi(left);
		float float_part = stof("0." + right);
		left = "";
		right = "";
		while (int_part > 0) {
			left = to_string(int_part % 2) + left;
			int_part >>= 1;
		}

		while (float_part > 0) {
			float_part *= 2;
			if (float_part >= 1) {
				right = right + "1";
				float_part -= 1;
			}
			else {
				right = right + "0";
			}
		}
		return left + "." + right;
	}
};