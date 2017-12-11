#include <iostream>
#include <queue>

using namespace std;

vector<int> KSmallest(vector<int> nums, int k) {
    priority_queue<int> pq;
    for(int i = 0; i < k; i++) {
        pq.push(nums[i]);
    }

    for(int i = k; i < nums.size(); i++) {
        if(nums[i] < pq.top()) {
            int t = pq.top();
            cout << pq.top() << endl;
            pq.push(nums[i]);
            pq.pop();
        }
    }

    vector<int> result(k);
    for(int i = k-1; i >= 0; i--) {
        result[i] = pq.top();
        pq.pop();
    }
    return result;
}