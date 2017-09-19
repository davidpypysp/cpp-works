#include <iostream>
#include <string>
using namespace std;

class L67 {
public:
    string addBinary(string a, string b) {
        if(a.size() > b.size()) return addBinary(b, a);
        
        int i1 = a.size()-1, i2 = b.size()-1;
        string result = "";
        int carry = 0;
        while(i2 >= 0) {
            int num1 = (i1 >= 0 ? a[i1--] - '0' : 0);
            int num2 = b[i2--] - '0';
            int sum = num1 + num2 + carry;
            int num = sum & 1;
            carry = (sum >> 1) & 1;
            result = (num == 1 ? '1' : '0') + result;
        }
        if(carry) result = '1' + result;
        return result;
        
    }
};