#include <iostream>
#include <stdio.h>
using namespace std;

class L402 {
public:
    string removeKdigits(string num, int k) {
        int n = num.length();
        string result = "";
        int index = 0;
        int the_index = 0;
        int cnt = 0;
        int val = 10;
        int lead_zero = true;
        int right = k;
        while(index < n) {
            int v = num[index] - '0';
            if(v < val) {
                val = v;
                the_index = index;
            }
            index++;
            if(index > right + cnt) {
                if(lead_zero == false || val != 0) {
                    lead_zero = false;
                    result += to_string(val);
                }
                index = the_index + 1;
                cnt++;
                val = 10;
            }
        }
        return result;
    }
};