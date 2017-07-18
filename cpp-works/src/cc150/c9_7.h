#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>

using namespace std;

struct Person {
    int height;
    int weight;

    Person(int h, int w) {
        height = h;
        weight = w;
    }

    bool operator < (const Person &a) const {
        if(height == a.height) return weight < a.weight;
        return height < a.height;
    }
};

class C9_7 {
public:
    int FindMaxSequence(Person arr[], int n) {
        std::sort(arr, arr+n);

        int b[n];
        int b_last = -1;
        int max = 0;
        for(int i = 0; i < n; i++) {
            if(b_last == -1 || arr[i].weight > b[b_last]) {
                b[++b_last] = arr[i].weight;
                max++;
            }
            else {
                int index = BinarySearch(b, b_last+1, arr[i].weight);
                b[index] = arr[i].weight;

            }
        }
        return max;
    }

    int BinarySearch(int arr[], int n, int elem) {
        int l = 0, r = n-1;
        while(l <= r) {
            int m = l + (r-l) / 2;
            if(elem <= arr[m]) r = m-1;
            else l = m+1;
        }
        return l;
    }

};


