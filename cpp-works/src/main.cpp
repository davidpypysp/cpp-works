#include <iostream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <algorithm>
#include <queue>
#include <vector>
#include <regex>
#include "util/adjacent_list.h"

#include "forusall/movie.h"
using namespace std;



int main() {
	vector<int> nums = {6, 1, 4, 6, 3, 2, 7, 4};

	int result = MaxMovie(nums, 3, 2);
	cout << result << endl;
}
