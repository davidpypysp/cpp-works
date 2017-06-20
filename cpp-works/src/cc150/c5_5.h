

class C5_5 {
	int BitSwapRequired(int a, int b) {
		int count = 0;
		for(int c = a ^ b; c != 0; c >>= 1) {
			count += c & 1;
		}
		return count;
	}
};