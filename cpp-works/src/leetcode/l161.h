#include <iostream>
#include <string>
using namespace std;


class L161 {
public:
    bool isOneEditDistance(string s, string t) {
        if(s.size() > t.size()) return isOneEditDistance(t, s);
        
        if(t.size() - s.size() > 1) return false;
        if(t.size() == s.size()) {
            int diff = 0;
            for(int i = 0; i < t.size(); i++) {
                if(s[i] != t[i]) diff++;
                if(diff > 1) return false;
            }
            return diff == 1;
        }
        else {
            for(int i = 0; i < t.size(); i++) {
                if(s.substr(0, i) == t.substr(0, i) && s.substr(i, string::npos) == t.substr(i+1, string::npos)) return true;
            }
            return false;
        }
        
    }
};