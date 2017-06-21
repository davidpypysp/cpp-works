#ifndef TEST_UTIL_H_
#define TEST_UTIL_H_

#include <iostream>
#include <string>

using namespace std;

string BinaryString(int n) {
	string s = "";
	while (n != 0) {
		s = to_string(n & 1) + s;
		n >>= 1;
	}
	return s;
}

#endif // TEST_UTIL_H_