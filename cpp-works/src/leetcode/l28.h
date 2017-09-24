#include <iostream>
#include <string>
#include <vector>
using namespace std;


class L28 {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() == 0) return 0;
        vector<int> next = getNext(needle);
        int i = 0, j = 0;
        while(i < (int)haystack.length() && j < (int)needle.length()) {
            if(j == -1 || haystack[i] == needle[j]) {
                i++;
                j++;
            }
            else {
                j = next[j];
            }
        }
        if(j == needle.size()) return i - j;
        return -1;
        
    }
    
    vector<int> getNext(string s) {
        vector<int> next(s.size());
        next[0] = -1;
        int pre = -1, post = 0;
        while(post < s.size()-1) {
            if(pre == -1 || s[pre] == s[post]) next[++post] = ++pre;
            else pre = next[pre];
        }
        return next;
    }
};