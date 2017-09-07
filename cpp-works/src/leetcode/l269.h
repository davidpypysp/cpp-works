#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <unordered_set>
using namespace std;


class L269 {
public:
    const int unvisited = 0, visiting = 1, visited = 2;
    string alienOrder(vector<string>& words) {
        if(words.size() == 0) return "";
        if(words.size() == 1) return words[0];
        unordered_map<char, unordered_set<char>> g;
        unordered_map<char, int> state;
        for(string word : words) {
            for(char c : word) state[c] = unvisited;
        }

        for(int i = 1; i < words.size(); i++) {
            string cur = words[i], prev = words[i-1];
            for(int j = 0; j < cur.size() && j < prev.size(); j++) {
                if(cur[j] != prev[j]) {
                    g[prev[j]].insert(cur[j]);
                    break;
                }
            }
        }
        string s = "";
        for(pair<char, int> p : state) {
            if(p.second == unvisited) {
                if(dfs(p.first, g, state, s) == false) return "";
            }
        }
        return s;
        
    }
    
    bool dfs(char c, unordered_map<char, unordered_set<char>> &g, unordered_map<char, int> &state, string &s) {
        state[c] = visiting;
        for(char next : g[c]) {
            if(state[next] == visiting) return false;
            else if(state[next] == unvisited) {
                if(dfs(next, g, state, s) == false) return false;
            }
        }
        state[c] = visited;
        s = c + s;
        return true;
    }
};