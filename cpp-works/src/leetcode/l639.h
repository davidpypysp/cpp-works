#include <iostream>
#include <string>
#include <math.h>
using namespace std;
class L639 {
public:
    int numDecodings(string s) {
        long mod = pow(10, 9) + 7;
        int n = s.size();
        if(n == 0) return 0;
        long next1 = 1, next2 = 1;
        if(s[n-1] == '*') next1 = 9;
        else if(s[n-1] == '0') next1 = 0;
        long cur = next1;
        for(int i = n-2; i >= 0; i--) {
            if(s[i] == '0') cur = 0;
            else if(s[i] == '*') {
                cur = (9 * next1) % mod;
                if(s[i+1] == '*') cur = (cur + (15 * next2) % mod) % mod;
                else if(s[i+1] <= '6') cur = (cur + (next2 << 1) % mod) % mod;
                else cur = (cur + next2) % mod;
            }
            else {
                cur = next1 % mod;
                if(s[i] == '1') {
                    if(s[i+1] == '*') cur = (cur + (9 * next2) % mod) % mod;
                    else cur = (cur + next2) % mod;
                }
                else if(s[i] == '2') {
                    if(s[i+1] == '*') cur = (cur + (6 * next2) % mod) % mod;
                    else if(s[i+1] <= '6') cur = (cur + next2) % mod;
                }
            }
            next2 = next1;
            next1 = cur;
        }
        return cur;
    }
};