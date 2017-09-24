#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct cmp {
    bool operator () (const pair<int, int> &a, const pair<int, int> &b) {
        return a.second < b.second;
    }
};


class L621 {

public:
    int leastInterval(vector<char>& tasks, int n) {
        int cnts[26];
        memset(cnts, 0, sizeof(cnts));
        for(char c : tasks) {
            cnts[c - 'A']++;
        }
        
        priority_queue<int, vector<int>, greater<int>> pq; 
        for(int i = 0; i < 26; i++) {
            if(cnts[i]) pq.push(cnts[i]);
        }
        
        int time = 0, cool = 0;
        vector<int> v;
        while(true) {
            if(!pq.empty()) {
                int num = pq.top();
                pq.pop();
                if(num > 1) {
                    v.push_back(num-1);
                }                
            }
            time++;
            cool++;
            if(cool == n+1) {
                if(v.size() == 0) break;
                cool = 0;
                for(int num : v) pq.push(num);
                v.clear();
            }
        }
        return time;
    }
    
};