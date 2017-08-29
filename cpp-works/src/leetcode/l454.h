#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class L454 {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int result = 0;
        unordered_map<int, int> map;
        int n = A.size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                map[A[i] + B[j]]++;
            }
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(map.find(-(C[i] + D[j])) != map.end()) result += map[-(C[i] + D[j])];
            }
        }
        return result;
    }
};