#include <iostream>
#include <vector>
using namespace std;

class L661 {
private:
    const int dir[9][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 0}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        for(int y = 0; y < M.size(); y++) {
            for(int x = 0; x < M[y].size(); x++) {
                int cnt = 0;
                int sum = 0;
                for(int i = 0; i < 9; i++) {
                    int ny = y + dir[i][0];
                    int nx = x + dir[i][1];
                    if(ny >= 0 && ny < M.size() && nx >= 0 && nx <M[ny].size()) {
                        sum += M[ny][nx] & 255;
                        cnt ++;
                    }
                }
                int new_val = sum / cnt;
                M[y][x] += (new_val << 8);
            }
        }
        
        for(int y = 0; y < M.size(); y++) {
            for(int x = 0; x < M[y].size(); x++) {
                M[y][x] >>= 8;
            }
        }
        return M;
        
    }
    

    
};