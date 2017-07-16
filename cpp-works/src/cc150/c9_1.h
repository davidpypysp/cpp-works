#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

class C9_1 {
public:
    static void Merge(int a[], int b[], int n, int m) {
        int last = n+m-1;
        int a_last = n-1;
        int b_last = m-1;
        while(a_last >=0 && b_last >= 0) {
            if(b[b_last] >= a[a_last]) {
                a[last--] = b[b_last--];
            }
            else {
                a[last--] = a[a_last--];
            }
        }
        while(b_last >= 0) {
            a[last--] = b[b_last--];
        }
    }
};