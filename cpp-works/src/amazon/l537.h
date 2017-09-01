#include <iostream>
#include <string>
using namespace std;

class L537 {
public:
    string complexNumberMultiply(string a, string b) {
        int k1 = 0, m1 = 0;
        complex(a, k1, m1);
        int k2 = 0, m2 = 0;
        complex(b, k2, m2);
        int k = k1 * k2 - m1 * m2;
        int m = k1 * m2 + k2 * m1;
        return to_string(k) + "+" + to_string(m) + "i";
    }
    
    void complex(string &s, int &k, int &b) {
        string str = "";
        int i = 0;
        for(; s[i] != '+'; i++) {
            str += s[i];
        }
        k = stoi(str);
        i++;
        str = "";
        for(; s[i] != 'i'; i++) {
            str += s[i];
        }
        b = stoi(str);
    }
};