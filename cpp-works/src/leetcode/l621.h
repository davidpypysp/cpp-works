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
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        int letters[26];
        memset(letters, 0, sizeof(letters));
        for(char c : tasks) {
            letters[c - 'A']++;
        }
        for(int i = 0; i < 26; i++) {
            if(letters[i]) {
                pq.push({i, letters[i]});
            }
        }
        
        vector<pair<int, int>> v;
        int result = 0;
        int cnt = 0, empty_num = 0;
        while(true) {
            if(!pq.empty()) {
                pair<int, int> p = pq.top();
                pq.pop();
                p.second--;
                v.push_back(p);
            }
            else {
                empty_num++;
            }
            cnt++;
            result++;
            if(cnt > n) {
                for(auto &p : v) {
                    if(p.second) pq.push(p);
                }
                v.clear();
                if(pq.empty()) {
                    return result - empty_num;
                }
                cnt = 0;
                empty_num = 0;
            }
        }
        return result;
    }
};