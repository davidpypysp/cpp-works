#include <iostream>


class C8_1 {
public:
	int FiboIterative(int n) {
		if (n <= 2) return 1;
		int prev1 = 1, prev2 = 1;
		int cur = 0;
		for (int i = 3; i <= n; i++) {
			cur = prev1 + prev2;
			prev2 = prev1;
			prev1 = cur;
		}
		return prev1;
	}

	int FiboRecursive(int n) {
		if (n <= 2) return 1;
		return FiboRecursive(n - 1) + FiboRecursive(n - 2);
	}
};