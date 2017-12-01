#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0;arr_i < n;arr_i++){
       cin >> arr[arr_i];
    }
    
    sort(arr.begin(), arr.end());
    
    
    for(int i = 0; i < n; i++) {
        if(i == 0 || arr[i] > arr[i-1]) {
            cout << n - i << endl;
        }
    }
    
    
    return 0;
}