#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
using namespace std;


void decode(string s, vector<vector<char>> &board) {
    for(int i = 0; i < 16; i++) {
        board[i/4][i%4] = s[i];
    }
}

string encode(vector<vector<char>> &board) {
    string s;
    for(int i = 0; i < 16; i++) {
        s += board[i/4][i%4];
    }
    return s;
}

bool win(vector<vector<char>> &board) {
    bool flag = false;
    for(int i = 0; i < 4; i++) {
        flag = true;
        for(int j = 1; j < 4; j++) {
            if(board[i][j] == 'o' || (board[i][j] != board[i][j-1])) {
                flag = false;
                break;
            }
        }
        if(flag) return true;
    }

    for(int i = 0; i < 4; i++) {
        flag = true;
        for(int j = 1; j < 4; j++) {
            if(board[i][j] == 'o' || (board[j][i] != board[j-1][i])) {
                flag = false;
                break;
            }
        }
        if(flag) return true;
    }

    flag = true;
    for(int i = 1; i < 4; i++) {
        if(board[i][i] == 'o' || (board[i][i] != board[i-1][i-1])) {
            flag = false;
            break;
        }
    }
    if(flag) return flag;

    flag = true;
    for(int i = 1; i < 4; i++) {
        if(board[3-i][i] == 'o' || (board[3-i][i] != board[4-i][i-1])) {
            flag = false;
            break;
        }
    }
    if(flag) return flag;
    
    return false;
}

int checkboard(vector<vector<char>> board) {
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    string s = encode(board);
    queue<pair<string, int>> q;
    unordered_set<string> vis;
    vis.insert(s + 'x');
    q.push(make_pair(s+'x', 0));
    vis.insert(s + 'y');
    q.push(make_pair(s+'y', 0));


    while(!q.empty()) {
        pair<string, int> p = q.front();
        q.pop();
        decode(p.first, board);
        if(win(board)) return p.second;
        char prev = p.first[16];

        for(int i = 0; i < 16; i++) {
            int y = i/4, x = i%4;
            if((prev == 'x' && board[y][x] == 'y') || (prev == 'y' && board[y][x] == 'x')){
                char c = board[y][x];
                for(int k = 0; k < 4; k++) {
                    int ny = y + dir[k][0];
                    int nx = x + dir[k][1];
                    if(ny >= 0 && ny < 4 && nx >= 0 && nx >= 0 && nx < 4 && board[ny][nx] == 'o') {
                        board[ny][nx] = c;
                        board[y][x] = 'o';
                        string s2 = encode(board) + c;
                        if(vis.find(s2) == vis.end()) {
                            vis.insert(s2);
                            q.push(make_pair(s2, p.second+1));
                        }
                        board[y][x] = c;
                        board[ny][nx] = 'o';
                    }
                }
            }
        }
    }
    return -1;
}

