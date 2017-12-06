#include <iostream>
#include <stdio.h>

using namespace std;


double mysqrt(double x, double p) {
    if(x < 0) return -1;
    double l = 0.0, r = x, mid = 0;
    while(l + p < r) {
        mid = (l+r) / 2.0;
        double sqr_left = (mid-p) * (mid-p);
        double sqr_right = (mid+p) * (mid+p);
        if(x >= sqr_left && x <= sqr_right) return mid;
        else if(x < sqr_left) r = mid-p;
        else l = mid+p;
    }
    return mid;
}

double mysqrt2(double x) {
    if (x == 0) return 0;
    double last = 0.0;
    double res = 1.0;
    while (res != last)
    {
        last = res;
        res = (res + x / res) / 2;
    }
    return res;
}