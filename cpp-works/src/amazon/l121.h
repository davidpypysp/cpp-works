#include <iostream>
#include <vector>
using namespace std;

class L121 {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1) return 0;
        int goup = false;
        int result = 0;
        int min_val = prices[0];
        for(int i = 1; i < prices.size(); i++) {
            goup = (prices[i] >= prices[i-1]);
            if(goup) {
                result = max(result, prices[i] - min_val);
            }
            else {
                min_val = min(min_val, prices[i]);
            }
        }
        return result;
    }
};