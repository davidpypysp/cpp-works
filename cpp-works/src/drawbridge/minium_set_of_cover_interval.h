#include <iostream>
#include <vector>

using namespace std;

struct cmp {
    bool operator () (pair<int, int> &p1, pair<int, int> &p2) {
        if(p1.first == p2.first) return p1.second < p2.second;
        return p1.first < p2.first;
    }
} cmp;

vector<pair<int, int>> MiniumSet(vector<pair<int, int>> &set) {

    sort(set.begin(), set.end(), cmp);
    vector<pair<int, int>> result;
    int right = 0;
    for(pair<int, int> p : set) {
        if(result.empty()) {
            right = p.second;
            result.push_back(p);
        }
        if(p.first > right) right = result.back().second;
        if(p.second > right) {
            if(result.back().second == right) {
                result.push_back(p);
            }
            else if(p.second > result.back().second) {
                result.pop_back();
                result.push_back(p);
            }
        }
        if(result.back().first >= right) right = result.back().second;
        
    }


    cout << "finished" << endl;
    return set;
}