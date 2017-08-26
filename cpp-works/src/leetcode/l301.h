#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;


class L301 {
public:
    struct Node {
        int bit;
        int num;
        int pos;
        Node(int bit, int num, int pos) : bit(bit), num(num), pos(pos) {
        }
    };
    
    
    vector<string> removeInvalidParentheses(string s) {
        int n = s.length();
        
        vector<string> result;
        
        queue<Node> q;
        q.push(Node(0, 0, -1));
        
        unordered_set<string> set;
        int min_num = n;
        
        while(!q.empty()) {
            Node node = q.front();
            q.pop();
            if(node.num > min_num) break;
            
            if(valid(s, node.bit)) {
                min_num = node.num;
                string ss = "";
                for(int b = node.bit, i = 0; b != 0; b >>= 1, i++) {
                    if(!(b&1)) {
                        ss += s[i];
                    }
                }
                if(set.find(ss) == set.end()) {
                    set.insert(ss);
                    result.push_back(ss);
                }
            }
            
            for(int i = node.pos+1; i < n; i++) {
                if(s[i] != '(' && s[i] != ')') continue;
                int new_bit = node.bit | (1 << i);
                q.push(Node(new_bit, node.num+1, i));
            }
            
        }
        return result;
        
        
        
    }
    
    bool valid(string s, int bit) {
        int n = s.length();
        int cnt = 0;
        for(int i = 0; i < n; i++, bit>>=1) {
            if(bit & 1) continue;
            if(s[i] == '(') cnt++;
            else if(s[i] == ')') cnt--;
            if(cnt < 0) return false;
        }
        return cnt == 0;
    }
    
};