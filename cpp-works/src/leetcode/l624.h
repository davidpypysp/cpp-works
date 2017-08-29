#include <iostream>
#include <vector>
using namespace std;


class L624 {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int min_val = INT_MAX, max_val = INT_MIN;
        int min_index = -1, max_index = -1;
        for(int i = 0; i < arrays.size(); i++) {
            if(arrays[i][0] < min_val) {
                min_val = arrays[i][0];
                min_index = i;
            }
            if(arrays[i][arrays[i].size() - 1] > max_val) {
                max_val = arrays[i][arrays[i].size()-1];
                max_index = i;
            }
        }
        if(min_index != max_index) return max_val - min_val;
        
        int min_val2 = INT_MAX, max_val2 = INT_MIN;
        int min_index2 = INT_MAX, max_index2 = INT_MIN;
        for(int i = 0; i < arrays.size(); i++) {
            if(i != max_index && arrays[i][0] < min_val2) {
                min_val2 = arrays[i][0];
                min_index2 = i;
            }
            if(i != min_index && arrays[i][arrays[i].size()-1] > max_val2) {
                max_val2 = arrays[i][arrays[i].size()-1];
                max_index2 = i;
            }
        }
        int dis1 = max_val2 - min_val, dis2 = max_val - min_val2;
        return dis1 > dis2 ? dis1 : dis2;
        
    }
};