#include <iostream>
#include <string>
using namespace std;
class L340 {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if(s.size() == 0 || k == 0) return 0;
        bool letters[256];
        int switch_indices[256];
        memset(letters, 0, sizeof(letters));
        int distinct_num = 0;
        int result = 0;
        int left = 0;
        for(int i = 0; i < s.size(); i++) {
            char c = s[i];
            if(!letters[c]) {
                if(distinct_num < k) distinct_num++;
                else {
                    while(true) {
                        if(s[left] != s[left+1] && left >= switch_indices[s[left]]) {
                            letters[s[left++]] = false;
                            break;
                        }
                        left++;
                    }
                }
                letters[c] = true;
                switch_indices[c] = i;
            }
            else if(c != s[i-1]) switch_indices[c] = i;
            result = max(result, i - left + 1);
        }
        return result;
    }
};