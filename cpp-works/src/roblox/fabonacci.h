#include <iostream>
#include <vector>

using namespace std;

class Fabonacci {
private: 
    static vector<vector<int>> matrix_mul2(vector<vector<int>> &a, vector<vector<int>> &b) {
        vector<vector<int>> result;
        for(int i = 0; i < 2; i++) {
            vector<int> v;
            for(int j = 0; j < 2; j++) {
                int val = 0;
                for(int k = 0; k < 2; k++) {
                    val += a[i][k] * b[k][j];
                }
                v.push_back(val);
            }
            result.push_back(v);
        }
        return result;
    }

    static vector<vector<int>> matrix_pow(int n) {
        vector<vector<int>> unit = {{1, 1}, {1, 0}};
        if(n == 1) {
            return unit;
        }
        else if(n & 1) { // odd
            vector<vector<int>> m = matrix_pow((n-1) >> 1);
            m = matrix_mul2(m, m);
            return matrix_mul2(m, unit);
        }
        else { // even
            vector<vector<int>> m = matrix_pow(n >> 1);
            return matrix_mul2(m, m);

        }
    }
public: 
    static int fibonacci(int n) {
        if(n <= 2) return 1;
        vector<vector<int>> m = matrix_pow(n-1);
        return m[0][0];
    }

};