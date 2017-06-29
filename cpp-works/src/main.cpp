#include <iostream>
#include "cc150/c5_2.h"
#include <string>
#include <stdlib.h>
#include "util/adjacent_list.h"
using namespace std;



int main() {
	string s = "0.33";
	C5_2 c5_2;
	string result = c5_2.DecToBin(s);
	cout << "result = " + result << endl;
	return 0;
}
