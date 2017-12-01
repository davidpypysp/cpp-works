#include <iostream>
#include <vector>

using namespace std;

int validate(string s) {
    int cnt = 0;
    for(char c : s) {
        if(c == '<') cnt++;
        else cnt--;
    }
    if(cnt > 0) return -1;
    return abs(cnt);
}
