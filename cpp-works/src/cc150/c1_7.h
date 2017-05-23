#include <iostream>
#include <vector>
using namespace std;


// use two array two save column zero and row zero information
void SetZeros1(vector<vector<int>> &matrix) {
	if (matrix.size == 0) return;
	int n = matrix.size();
	int m = matrix[0].size();

	int *row = new int[n];
	int *col = new int[m];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (matrix[i][j] == 0) {
				row[i] = 1;
				col[j] = 1;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (row[i] == 0 || col[j] == 0)
				matrix[i][j] = 0;
		}
	}

}

void SetZero2(vector<vector<int>> &matrix) {
	if (matrix.size == 0) return;
	int n = matrix.size();
	int m = matrix[0].size();

	for (int i = 0; i < n; i++) {
		bool zero_flag = false;
		for (int j = 0; j < m; j++) {
			if (matrix[i][j] == 0) {
				zero_flag = true;
				matrix[i][j] = -1;
			}
		}
		if (zero_flag) {
			for (int j = 0; j < m; j++) {
				if (matrix[i][j] == 1) matrix[i][j] = 0;
			}
		}
	}

	for (int j = 0; j < m; j++) {
		bool zero_flag = false;
		for (int i = 0; i < n; i++) {
			if (matrix[i][j] == -1) {
				zero_flag = true;
				break;
			}
		}
		if (zero_flag) {
			for (int i = 0; i < n; i++) {
				matrix[i][j] = 0;
			}
		}
	}

}

