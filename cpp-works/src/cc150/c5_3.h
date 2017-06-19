#include <iostream>
#include <string>

using namespace std;


class C5_3 {
public:
	int FindNextSmallest(int n) {
		int t = 1;
		int index = 0;
		int num = 0;
		bool find_one = false;

		while (true) {
			if (!find_one) {
				if (n & t) {
					find_one = true;
				}
			}
			else {
				if (!(n & t)) {
					n |= t;
					n &= ~(t - 1);
					break;
				}
				else {
					num++;
				}
			}
			t <<= 1;
			index++;
		}
		t = 1;
		for (int i = 0; i < num; i++) {
			n |= t;
			t <<= 1;
		}

		return n;


	}

	int FindNextLargest(int n) {
		int t = 1;
		int num = 0;
		bool find_zero = false;
		while (true) {
			if (!find_zero) {
				if (!(n & t)) {
					find_zero = true;
				}
				else {
					num++;
				}
			}

			else {
				if (n & t) {
					n &= ~t;
					n &= ~(t-1);
					n |= (t >> 1);
					break;
				}
			}
			t <<= 1;
		}
		t >>= 2;
		for (int i = 0; i < num; i++) {
			n |= t;
			t >>= 1;
		}
		return n;

	}

	string BinaryString(int n) {
		string s = "";
		while (n != 0) {
			s = to_string(n & 1) + s;
			n >>= 1;
		}
		return s;
	}
};
