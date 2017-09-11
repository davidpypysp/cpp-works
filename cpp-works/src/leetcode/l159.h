#include <iostream>
#include <string>
using namespace std;
class L159 {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        if(s.size() == 0) return 0;
        char c1 = s[0], c2;
        int num = 1;
        int left = 0;
        int switch_index = 0;
        int result = 1;
        for(int i = 1; i < s.size(); i++) {
            if(num == 1) {
                if(s[i] != c1) {
                    switch_index = i;
                    c2 = s[i];
                    num++;
                }
            }
            else if(num == 2) {
                if(s[i] == c1) {
                    switch_index = i;
                    c1 = c2;
                    c2 = s[i];
                }
                else if(s[i] != c2) {
                    left = switch_index;
                    switch_index = i;
                    c1 = c2;
                    c2 = s[i];
                }
            }
            result = max(result, i - left+1);
        }
        return result;
    }
};