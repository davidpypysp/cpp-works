#include <iostream>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <queue>
#include <vector>
#include "util/adjacent_list.h"


#include "leetcode/l140.h"
#include "leetcode/l22.h"
#include "leetcode/l621.h"
#include "leetcode/l128.h"
#include "leetcode/l28.h"
#include "leetcode/l324.h"
#include "leetcode/l433.h"
using namespace std;



int main() {
	string start = "AACCGGTT";
	string end = "AACCGGTA";
	vector<string> bank = {"AACCGGTA"};
	L433 l;
	l.minMutation(start, end, bank);
	return 0;
}
