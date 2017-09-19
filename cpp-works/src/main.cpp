#include <iostream>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <queue>
#include "util/adjacent_list.h"


#include "leetcode/l140.h"
#include "leetcode/l22.h"
using namespace std;

struct cmp {
    bool operator () (int a, int b) {
        return a < b;
    }
};

int main() {
	L22 l;
	l.generateParenthesis(3);

	return 0;
}
