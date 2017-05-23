/*
	Implement an algorithm to determine if a string has all unique characters.
	What if you can not use additional data structures
*/

#include <string>

using namespace std;



/*
	use a bool array to save the state of every letter
	time: O(n), space: O(n);
*/
bool isUniqueChar(string &str) {
	bool check[256];
	memset(check, 0, sizeof(check));
	for (int i = 0; i < str.size(); i++) {
		int index = str[i] - 'a';
		if (check[index]) return false;
		else check[index] = true;
	}
	return true;
}

/*
	use an interger(32 bit) to save all letter's state.
	each letter use 1 bit to judge the state
	time: o(n) space: o(1);
*/
bool isUniqueChar2(string &str) {
	int state = 0;
	for (int i = 0; i < str.size(); i++) {
		int index = str[i] - 'a';
		if (state & (1 << index)) return false;
		else state |= (1 << index);
	}
	return true;
}



