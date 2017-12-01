#include <iostream>
using namespace std;

int strcmp_impl(const char *s1, const char *s2) { // s1: abc, s2: abcd
    while(*s1 && (*s1==*s2)) s1++,s2++;
    return *(const unsigned char*)s1-*(const unsigned char*)s2;
}