#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;


class C9_5 {
public:
    int Search(string strings[], string str, int n) {
        return SearchString(strings, str, 0, n);
    }

    int SearchString(string strings[], string str, int left, int right) {
        while(left <= right) {
            while(left <= right && strings[right] == "") right--;
            int mid = (left + right) / 2;
            while (strings[mid] == "") mid++;
            int cmp = str.compare(strings[mid]);
            if(cmp == 0) return mid;
            else if(cmp < 0) right = mid - 1;
            else left = mid + 1;
        }
        return -1;
    }

};
