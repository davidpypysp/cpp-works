#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int word(string s1, string s2) {
    unordered_map<char, int> map;
    for(int i = 0; i < s1.size(); i++) {
        char c = s1[i];
        if(map.find(c) == map.end()) {
            map[c] = i;
        }
    }

    int min_index = -1;
    for(int i = 0; i < s2.size(); i++) {
        char c = s2[i];
        if(map.find(c) != map.end()) {
            map[c] = min(i, map[c]);
            min_index = (min_index == -1) ? map[c] : min(min_index, map[c]);
        }
    }
    return min_index;
}
