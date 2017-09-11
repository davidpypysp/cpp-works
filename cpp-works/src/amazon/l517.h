#include <iostream>
#include <vector>
using namespace std;

class L517 {
public:
    int findMinMoves(vector<int>& machines) {
        int sum = 0;
        for(int num : machines) sum += num;
        if(sum % machines.size() != 0) return -1;
        int avg = sum / machines.size();
        int result = 0;
        int cnt = 0;
        for(int load :machines) {
            cnt += load - avg;
            result = max(result, max(abs(cnt), load - avg));
        }
        return result;
    }
};