#include <iostream>
#include <string>
using namespace std;

class L344 {
public:
    string reverseString(string s) {
        for(int l = 0, r = s.size()-1; l < r; l++, r--) {
            char c = s[l];
            s[l] = s[r];
            s[r] = c;
        }
        return s;
    }
};