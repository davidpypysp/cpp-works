#include <iostream>

using namespace std;

void Rotate90(int **image, int n) {
	for (int layer = 0; layer < n / 2; layer++) {
		int first = layer, last = n - 1 - layer;
		for (int i = first; i < last; i++) {
			int offset = i - first;
			int lt = image[first][i];
			image[first][i] = image[last - offset][first];
			image[last - offset][first] = image[last][last - offset];
			image[last][last - offset] = image[i][last];
			image[i][last] = lt;
		}
	}
}