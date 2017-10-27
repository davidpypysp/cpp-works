#include <iostream>
#include <string>
using namespace std;

int countPalindroms(string s) {
    int n = s.size();
    if(n == 0) return 0;
    int result = 0;
    bool d[n];
    for(int r = 0; r < n; r++) {
        for(int l = 0; l < r; l++) {
            d[l] = false;
            if(s[l] == s[r] && (l+1 == r || d[l+1])) {
                d[l] = true;
                result++;
            }
        }
        result++;
        d[r] = true;
    }
    return result;
}