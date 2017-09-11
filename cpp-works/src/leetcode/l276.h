#include <iostream>
using namespace std;
class L276 {
public:
    int numWays(int n, int k) {
        if(n == 0) return 0;
        int diff = k, same = 0;
        for(int i = 1; i < n; i++) {
            int next_diff = (k-1) * (diff + same);
            same = diff;
            diff = next_diff;
        }
        return diff + same;
    }
};