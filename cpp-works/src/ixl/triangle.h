#include <iostream>
#include <vector>
using namespace std;

vector<string> TriangleOrNot(vector<int> a, vector<int> b, vector<int> c) {
    vector<string> result;
    for(int i = 0; i < a.size(); i++) {
        int aa = a[i], bb = b[i], cc = c[i];
        if(aa <= 0 || bb <= 0 || cc <= 0) result.push_back("No");
        else if(aa + bb <= cc || bb + cc <= aa || cc + aa <= bb) result.push_back("No");
        else result.push_back("Yes");
    }
    return result;
}