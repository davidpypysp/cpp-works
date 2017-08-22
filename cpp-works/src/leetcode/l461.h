#include <iostream>
#include <string>

using namespace std;

class L461 {
public:
    int hammingDistance(int x, int y) {
        int diff = x ^ y;
        int result = 0;
        while(diff) {
            result++;
            diff = diff & (diff-1);
        }
        return result;
    }
};
