#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

struct UnionSet {
    int size;
    vector<int> set;
    
    UnionSet(int size) : size(size) {
        for(int i = 0; i < size; i++) {
            set.push_back(i);
        }
    }
    
    int Find(int index) {
        if(index != set[index]) set[index] = Find(set[index]);
        return set[index];
    }
    
    void Connect(int index1, int index2) {
        int p1 = Find(index1);
        int p2 = Find(index2);
        set[p2] = p1;
    }
};


class L200 {
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        if(row == 0) return 0;
        int col = grid[0].size();
        UnionSet us(row * col);
        int roots[row * col];
        memset(roots, 0, sizeof(roots));
        
        for(int i = 0, index = 0; i < row; i++) {
            for(int j = 0; j < col; j++, index++) {
                if(grid[i][j] == '1') {
                    if(i > 0 && grid[i-1][j] == '1') {
                        us.Connect(index - col, index);
                    }
                    if(j > 0 && grid[i][j-1] == '1') {
                        us.Connect(index - 1, index);
                    }
                    
                }
            }
        }
        
        int result = 0;
        for(int i = 0, index = 0; i < row; i++) {
            for(int j = 0; j < col; j++, index++) {
                if(grid[i][j] == '0') continue;
                int root = us.Find(index);
                if(roots[root] == false) {
                    roots[root] = true;
                    result++;
                }
            }
        }
        return result;
        
    }
};