#include <iostream>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include "util/adjacent_list.h"

#include "amazon/l15.h"
#include "amazon/l438.h"
#include "amazon/l532.h"
#include "leetcode/l228.h"
#include "amazon/l200.h"
#include "leetcode/l305.h"

using namespace std;



int main() {
	L305 l;
	pair<int, int> p(1, 0);
	vector<pair<int, int>> v;
	v.push_back(p);
	l.numIslands2(3, 1, v);


}
