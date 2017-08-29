#include <iostream>
#include <string>
using namespace std;
class L387 {
public:
    int firstUniqChar(string s) {
        if(s.size() == 0) return -1;
        int cnts[26];
        memset(cnts, 0, sizeof(cnts));
        int left = 0, right = 0;
        while(right < s.size()) {
            cnts[s[right] - 'a']++;
            while(left <= right && cnts[s[left] - 'a'] > 1) left++;
            right++;
        }
        return left == s.size() ? -1 : left;
    }
};