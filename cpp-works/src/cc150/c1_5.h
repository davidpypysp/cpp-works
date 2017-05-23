#include <iostream>



void Replace20(char str[], int n) {
	int space_num = 0;
	for (int i = 0; i < n; i++) {
		if (str[i] == ' ') space_num++;
	}

	int new_length = n + space_num * 2;
	str[new_length] = '\0';

	for (int i = n - 1; i >= 0; i--) {
		if (str[i] == ' ') {
			str[--new_length] = '0';
			str[--new_length] = '2';
			str[--new_length] = '%';
		}
		else {
			str[--new_length] = str[i];
		}
	}

}

