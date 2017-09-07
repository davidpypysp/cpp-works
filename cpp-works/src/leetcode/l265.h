#include <iostream>
#include <vector>
using namespace std;

class L265 {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size();
        if(!n) return 0;
        int k = costs[0].size();
        
        pair<int, int> min1, min2;
        pair<int, int> prev_min1 = {0, -1}, prev_min2 = {0, -1}; // first = min_val, second = min_index
        for(int i = n-1; i >= 0; i--) {
            min1.first = INT_MAX, min2.first = INT_MAX;
            for(int j = 0; j < k; j++) {
                int val = costs[i][j] + (j == prev_min1.second ? prev_min2.first : prev_min1.first);
                if(val <= min1.first) {
                    min2 = min1;
                    min1 = make_pair(val, j);
                }
                else if(val <= min2.first) {
                    min2 = make_pair(val, j);
                }
            }
            prev_min1 = min1;
            prev_min2 = min2;
        }
        return min1.first;
    }
};