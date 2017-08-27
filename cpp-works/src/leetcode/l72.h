#include <iostream>
#include <stdio.h>
using namespace std;


class L72 {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        int d[n1+1][n2+1];
        d[0][0] = 0;
        for(int i = 1; i <= n1; i++) 
            d[i][0] = i;
        for(int i = 1; i <= n2; i++)
            d[0][i] = i;
        
        for(int i = 1; i <= n1; i++) {
            for(int j = 1; j <= n2; j++) {
                if(word1[i-1] == word2[j-1]) d[i][j] = d[i-1][j-1];
                else {
                    d[i][j] = min(d[i-1][j] + 1, min(d[i][j-1] + 1, d[i-1][j-1] + 1));
                }
            }
        }
        return d[n1][n2];
    }
};