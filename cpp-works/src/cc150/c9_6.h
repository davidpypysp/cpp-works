#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

class C9_6 {
public:
    bool FindElem(int** matrix, int n, int m, int elem) {

    }

    bool BinarySearch(int** matrix, int elem, int left, int right, int top, int bottom) {
        if(left <= right && top <= bottom) {
            int mid_x = (left + right) / 2;
            int mid_y = (top + bottom) / 2;
            if(elem == matrix[mid_y][mid_x]) return true;

            if(elem < matrix[mid_y][mid_x]) {
                if(BinarySearch(matrix, elem, left, mid_x - 1, mid_y, bottom)) return true;
                if(BinarySearch(matrix, elem, left, right, top, mid_y - 1)) return true;
            }
            else {
                if(BinarySearch(matrix, elem, mid_x+1, right, top, mid_y)) return true;
                if(BinarySearch(matrix, elem, left, right, mid_y + 1, bottom)) return true;
            }
        }
        return false;
    }

    bool LinearSearch(int** matrix, int elem, int n, int m) {
        int row = 0;
        int col = m-1;
        while(row < n && col >= 0) {
            if(matrix[row][col] == elem) return true;
            if(elem < matrix[row][col]) col--;
            else row++;
        }
        return false;
    }

private:
};
