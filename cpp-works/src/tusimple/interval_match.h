#include <iostream>
#include <stdlib.h>
#include <vector>
#include <queue>

using namespace std;

struct cmp_left {
    bool operator () (pair<int, int> a, pair<int, int> b) {
        if(a.first == b.first) return a.second < b.second;
        return a.first < b.first;
    }
} cmp_left;

struct cmp_right {
    bool operator () (pair<int, int> a, pair<int, int> b) {
        if(a.second == b.second) return a.first > b.first;
        return a.second > b.second;
    }
};

int IntervalMatch(vector<int> points, vector<pair<int, int>> intervals) {
    sort(points.begin(), points.end());
    sort(intervals.begin(), intervals.end(), cmp_left);
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp_right> pq;

    int result = 0;
    int index = 0;
    for(int point : points) {
        while(index < intervals.size() && intervals[index].first <= point) {
            pq.push(intervals[index++]);
        }

        while(!pq.empty() && pq.top().second < point) pq.pop();
        if(!pq.empty()) {
            result++;
            pq.pop();
        }
    }
    return result;
}


