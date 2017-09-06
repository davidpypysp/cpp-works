#include <iostream>
using namespace std;

class L670 {
public:
    int maximumSwap(int num) {
        int digit[10];
        int index = -1;
        int val = num;
        while(val) {
            int d = val % 10;
            digit[++index] = d;
            val /= 10;
        }
        bool first_down = true;
        int max_val = -1, max_index = -1;
        for(int i = index-1; i >= 0; i--) {
            if(digit[i] > digit[i+1]) {
                first_down &= false;
            }
            if(!first_down) {
                if(digit[i] >= max_val) {
                    max_val = digit[i];
                    max_index = i;
                }
            }
        }
        if(first_down) return num;
        bool swap = false;
        val = 0;
        for(int i = index; i >= 0; i--) {
            if(!swap && digit[i] < max_val) {
                digit[max_index] = digit[i];
                digit[i] = max_val;
                swap = true;
            }
            val *= 10;
            val += digit[i];
        }
        return val;
    }
};