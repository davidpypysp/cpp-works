#include <iostream>
#include <string.h>
#include <unordered_map>
using namespace std;

int horse(string s, string horse) {
    unordered_map<char, char> prev;
    unordered_map<char, int> cnt;
    char first = horse[0], last = horse[4];
    for(int i = 0; i < 5; i++) {
        if(i == 0) prev[horse[i]] = -1;
        else prev[horse[i]] = horse[i-1];
        cnt[horse[i]] = 0;
    }

    int result = 0;
    int finished = 0;
    for(int i = 0; i < s.size(); i++) {
        char c = s[i];
        if(c == first) {
            if(finished == 0) result++;
            else finished--;
        }
        else {
            if(cnt[prev[c]] == 0) return -1;
            cnt[prev[c]]--;
        }
        cnt[c]++;

        if(c == last) {
            cnt[c]--;
            finished++;
        }
    }

    for(int i = 0; i < 5; i++) {
        if(cnt[horse[i]] != 0) return -1;
    }

    return result;
    
}
