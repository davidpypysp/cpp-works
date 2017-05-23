
#include <iostream>
#include <string>
using namespace std;

bool Anagram(const string s1, const string s2) {
	if (s1.length() != s2.length()) return false;
	int count[256];
	for (int i = 0; i < s1.length(); i++) {
		count[s1[i]]++;
		count[s2[i]]--;
	}
	for (int i = 0; i < 256; i++) {
		if (count[i] != 0) return false;
	}
	return true;
}