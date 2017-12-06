#include <iostream>
#include <vector>
using namespace std;


int MaxMovie(vector<int> &nums, int a, int b) {
    int n = nums.size();
    if(a == 0 && b == 0) return 0;
    if(a == 0 || b == 0) {
        int c = max(a, b);
        int sum = 0;
        int result = 0;
        for(int i = 0; i < n ; i++) {
            if(i < c) sum += nums[i];
            else {
                sum += nums[i] - nums[i-c];
            }
            result = max(result, sum);
        }
        return result;
    }

    vector<int> left_a(n), right_a(n);
    vector<int> left_b(n), right_b(n);

    int sum_a = 0;
    for(int i = 0; i < n; i++) {
        if(i < a) {
            sum_a += nums[i];
            left_a[i] = 0;
        }
        else {
            left_a[i] = max(left_a[i-1], sum_a);
            sum_a += nums[i] - nums[i-a];
        }
    }

    sum_a = 0;
    for(int i = n-1; i >= 0; i--) {
        if(n-i <= a) {
            sum_a += nums[i];
            right_a[i] = 0;
        }
        else {
            right_a[i] = max(right_a[i+1], sum_a);
            sum_a += nums[i] - nums[i+a];
        }
    }

    int sum_b = 0;
    for(int i = 0; i < n; i++) {
        if(i < b) {
            sum_b += nums[i];
            left_b[i] = 0;
        }
        else {
            left_b[i] = max(left_b[i-1], sum_b);
            sum_b += nums[i] - nums[i-b];
        }
    }

    sum_b = 0;
    for(int i = n-1; i >= 0; i--) {
        if(n-i <= b) {
            sum_b += nums[i];
            right_b[i] = 0;
        }
        else {
            right_b[i] = max(right_b[i+1], sum_b);
            sum_b += nums[i] - nums[i+b];
        }
    }

    int result = 0;
    for(int i = a; i <= n - b; i++) {
        result = max(result, left_a[i] + right_b[i-1]);;
    }

    for(int i = b; i <= n - a; i++) {
        result = max(result, left_b[i] + right_a[i-1]);
    }
    return result;



}