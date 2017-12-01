#include <iostream>
#include <vector>
using namespace std;

int count(int n) {
    int cnt = 0;
    while(n) {
        if(n & 1) cnt++;
        n >>= 1;
    }
    return cnt;
}

struct cmp {
    bool operator () (int v1, int v2) {
        return count(v1) < count(v2);
    }

} cmp;
vector<int> bin_sort(vector<int> arr) {
    sort(arr.begin(), arr.end(), cmp);
    return arr;
}