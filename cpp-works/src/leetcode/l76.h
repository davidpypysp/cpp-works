#include <iostream>
#include <string>
using namespace std;


class L76 {
public:
    string minWindow(string s, string t) {
        int tmap[256];
        memset(tmap, 0, sizeof(tmap));
        int cnts[256];
        memset(cnts, 0, sizeof(cnts));
        int tnum = 0;
        for(char c : t) {
            tmap[c]++;
        }
        int left = 0, right = 0;
        int num = 0;
        int len = s.size();
        string result = "";
        while(right < s.size()) {
            if(tmap[s[right]]) {
                cnts[s[right]]++;
                if(cnts[s[right]] <= tmap[s[right]]) num++;
                while(left < right) {
                    if(cnts[s[left]] == 0) {
                        left++;
                    }
                    else if(cnts[s[left]] > tmap[s[left]]) {
                        cnts[s[left]]--;
                        left++;
                    }
                    else break;
                }
                if(num == t.size() && right - left + 1 <= len) {
                    len = right - left + 1;
                    result = s.substr(left, len);
                }
            }
            right++;
        }
        return result;
    }
};