
int CountZero(int n) {
    if(n == 0) return 1;
    int result = 0;
    while(n) {
        int k = n % 10;
        if(k == 0 || k == 4 || k == 6 || k == 9) result++;
        else if(k == 8) result += 2;
        n /= 10;
    }
    return result; 
}