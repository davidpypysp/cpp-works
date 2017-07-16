#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

class C8_7 {
public:
    int coins[4] = {25, 10, 5, 1};

    int CalcCentWays(int n) {
        if(n < 1) return 0;
        return Calc(n, 0);
    }

private:
    int Calc(int n, int index) {
        if(index == 3) return 1;
        int result = 0;
        while(n >= 0) {
            result += Calc(n, index+1);
            n -=  coins[index];
        }
        return result;

    }
};