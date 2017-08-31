#include <vector>
#include <iostream>
using namespace std;
class L646 {
public:
    static bool comp(const vector<int> &a, const vector<int> &b) {
        if(a[1] == b[1]) return a[0] < b[0];
        return a[1] < b[1];
    }
    
    
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), comp);
        int result = 1;
        int left = 0;
        for(int i = 1; i < pairs.size(); i++) {
            if(pairs[i][0] > pairs[left][1]) {
                result++;
                left = i;
            }
        }
        return result;
        
    }
};