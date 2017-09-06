#include <iostream>
#include <vector>
using namespace std;

class L529 {
public:
    int dir[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int cy = click[0], cx = click[1];
        if(board[cy][cx] == 'M') {
            board[cy][cx] = 'X';
        }
        else if(board[cy][cx] == 'E') {
            dfs(board, cy, cx);
        }
        return board;
    }
    
    void dfs(vector<vector<char>>& board, int y, int x) {
        int mine_num = 0;
        vector<pair<int, int>> vec;
        for(int i = 0; i < 8; i++) {
            int ny = y + dir[i][0];
            int nx = x + dir[i][1];
            if(ny >= 0 && ny < board.size() && nx >= 0 && nx < board[y].size()) {
                if(board[ny][nx] == 'M') mine_num++;
                else if(board[ny][nx] == 'E') vec.push_back({ny, nx});
            }
        }
        if(mine_num) {
            board[y][x] = '0' + mine_num;
        }
        else {
            board[y][x] = 'B';
            for(auto &it : vec) {
                dfs(board, it.first, it.second);
            }
        }
    }
};