#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class L433 {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        char arr[] = {'A', 'C', 'G', 'T'};
        
        queue<string> q;
        queue<int> q_path;
        unordered_set<string> set;
        for(string s : bank) {
            set.insert(s);
        }
        
        q.push(start);
        q_path.push(0);
        
        while(!q.empty()) {
            string s = q.front();
            int path = q_path.front();
            q.pop();
            q_path.pop();
            
            if(s == end) {
                return path;
            }
            
            for(int i = 0; i < s.size(); i++) {
                for(int j = 0; j < 4; j++) {
                    if(s[i] == arr[j]) continue;
                    string next = s;
                    next[i] = arr[j];
                    if(set.find(next) != set.end()) {
                        set.erase(next);
                        q.push(next);
                        q_path.push(path+1);
                    }
                }
            }
            
        }
        return -1;
        
    }
};