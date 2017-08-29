#include <iostream>
#include <string>
using namespace std;


class L541 {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        if(n == 0) return s;
        int l = 0, r = min(k-1, n-1);
        int cnt = 0;
        while(1) {
            char c = s[l];
            s[l] = s[r];
            s[r] = c;
            if((++l) >= (--r)) {
                l = (++cnt) * 2 * k;
                if(l >= n) break;
                r = min(l + k - 1, n - 1);
            }
        }
        return s;
    }
};