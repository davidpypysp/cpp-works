/*
	Design an algorithm and write code to remove the duplicate characters in a string without using any additional buffer
*/

#include <iostream>

using namespace std;

void RemoveDupilcates(char str[]) {
	int n = 0;
	while (str[n] != '\0') n++;

	for (int i = 0; i < n; i++) {
		if (str[i] == '\0') continue;
		for (int j = i + 1; j < n; j++) {
			if (str[j] == str[i]) str[j] = '\0';
		}
	}
	int index = 0;
	for (int i = 0; i < n; i++) {
		if (str[i] == '\0') continue;
		str[index++] = str[i];
	}
	str[index] = '\0';

}