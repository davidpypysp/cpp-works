#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

bool prefix(string a, string b) {
    if(a.size() < b.size()) return false;
    for(int i = 0; i < b.size(); i++) {
        if(a[i] != b[i]) return false;
    }
    return true;
}

int main(){
    unordered_map<string, int> map;
    int result = 0;
    string s;
    for(auto &p : map) {
        if(prefix(p.first, s)) result += p.second;
    }
    return result;

    shared_ptr<string> a;
    shared_ptr<string> b(a);
    unique_ptr<string> a2;
    //unique_ptr<string> b2(a2);
    weak_ptr<string> a3;
    weak_ptr<string> b3(a3);

    
    
    return 0;
}