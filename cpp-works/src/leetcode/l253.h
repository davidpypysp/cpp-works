#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include "../leetcode_util/interval.h"

using namespace std;

struct cmp1 {
    bool operator() (Interval a, Interval b ) {
        if( a.start == b.start ) return a.end < b.end;
        return a.start < b.start; 
    }
} cmp1;

struct cmp2 {
    bool operator() (Interval a, Interval b ){
        return a.end < b.end; 
    }
};

class L253 {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp1);
        priority_queue<Interval,vector<Interval>, cmp2> pq;
        int num = 0;
        int max = 0;
        for(int i = 0; i < intervals.size(); i++) {
            while(!pq.empty() && intervals[i].start >= pq.top().end) {
                pq.pop();
                num--;
            }
            pq.push(intervals[i]);
            num++;
            max = num > max ? num : max;
        }
        return max;
    }
};