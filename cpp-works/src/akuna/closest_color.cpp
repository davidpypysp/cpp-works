#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int get_distance(char r1, char g1, char b1, char r2, char g2, char b2) {
    return (r1 - r2) * (r1 - r2) + (g1 - g2) * (g1 - g2) + (b1 - b2) * (b1 - b2);
}

int main(){

    char r, g, b;

    vector<vector<char>> colors;
    vector<int> distances;
    bool flag = false;
    int min = 255 * 255 * 3 + 1;
    for(int i = 0; i < colors.size(); i++) {
        distances.push_back(get_distance(r, g, b, colors[i][0], colors[i][1], colors[i][2]));
        if(distances[i] < min) {
            min = distances[i];
            flag = false;
        }
        else if(distances[i] == min) {
            flag = true;
        }
    }
    if(flag) cout << "Ambiguous" << endl;
    else cout << min << endl;

    
    
    return 0;
}