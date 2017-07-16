#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

class C9_3 {
public:
    int Search(int a[], int n, int x) {
        return BinarySearch(a, 0, n, x);
    }

    int BinarySearch(int a[], int l, int r, int x) {
        while(l <= r) {
            int m = (l+r) / 2;
            if(a[m] == x) return m;
            if(a[l] <= a[m]) {
                if(x >= a[m]) l = m+1;
                else if(x >= a[l]) r = m-1;
                else l = m+1;
            }
            else {
                if(x < a[m]) r = m-1;
                else if(x <= a[r]) l = m+1;
                else r = m-1;
            }
        }
        return -1;
    }
};
