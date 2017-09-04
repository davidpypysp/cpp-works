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
#include "amazon/l297.h"
#include "amazon/l449.h"
#include "amazon/l536.h"
#include "leetcode/l287.h"
#include "amazon/l640.h"
#include "leetcode/l381.h"
using namespace std;



int main() {
	RandomizedCollection rc;
	rc.insert(10);
	rc.insert(10);
	rc.insert(20);
	rc.insert(20);
	rc.insert(30);
	rc.insert(30);
	rc.remove(10);
	rc.remove(10);
	rc.remove(30);
	rc.remove(30);
	int val;
	val = rc.getRandom();

}
