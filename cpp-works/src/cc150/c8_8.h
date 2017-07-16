#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

class C8_8 {
public:
    int board[8];

    void EightQueen(int row) {
        if(row == 8) {
            Print();
        }
        for(int col = 0; col < 8; col++) {
            if(Check(row, col)) {
                board[row] = col;
                EightQueen(row+1);
            }
        }
    }

    bool Check(int row, int col) {
        for(int i = 0; i < row; i++) {
            if(board[i] == col) return false;
            if(board[i] - col == i - row || board[i] - col == row - i) return false;
        }
        return true;
    }

    void Print() {
        for(int i = 0; i < 8; i++) {
            for(int j = 0; j< 8; j++) {
                if(board[i] == j) cout << "*";
                else cout << "_";
            }
            cout << endl;
        }
        cout << endl;
    }

};
