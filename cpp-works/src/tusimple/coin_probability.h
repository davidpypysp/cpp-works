#include <iostream>
#include <vector>

using namespace std;

double coin(vector<double> p, int k) {
    int n = p.size();
    if(n == 0) return 0.0;
    double d[n+1][k+1];
    memset(d, 0, sizeof(d));
    d[0][0] = 1;
    for(int i = 1; i <= n; i++) {
        d[i][0] = (1-p[i-1]) * d[i-1][0];
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= k; j++) {
            if(k > j) break;
            d[i][j] = p[i-1] * d[i-1][j-1] + (1-p[i-1]) * d[i-1][j];
        }
    }
    return d[n][k];

}



double dfs(vector<double> &p, int index, int num) {
    if(index == p.size()) {
        if(num == 0) return 1.0;
        else return 0.0;
    }
    double result = 0;
    if(num > 0) result += p[index] * dfs(p, index+1, num-1);
    result += (1-p[index]) * dfs(p, index+1, num);
    return result;
}

double coin2(vector<double> p, int k) {
    double result = dfs(p, 0, k);
    return result;
}

