#include <iostream>
#include <string>
#include <stack>
#include <math.h>

using namespace std;

void calc(stack<float> &nums, stack<char> &ops) {
    float num1 = nums.top();
    nums.pop();
    float num2 = nums.top();
    nums.pop();
    char c = ops.top();
    ops.pop();
    float num3 = 0;
    if(c == '&') num3 = fmax(num1, num2);
    else if(c == '|') num3 = fmin(num1, num2);
    else if(c == '*') num3 = num1 * num2;
    else if(c == '+') num3 = num1 + num2;
    nums.push(num3);
}

float calculator(string input_str) {
    int i = 0, n = input_str.size();
    stack<float> nums;
    stack<char> ops;

    while(i < n) {
        char c = input_str[i];
        if(c == '-' || isdigit(c)) { // is number
            string s = "";
            s += c;
            while(i+1 < n && (isdigit(input_str[i+1]) || input_str[i+1] == '.')) {
                s += input_str[++i];
            }
            float num = stof(s);
            nums.push(num);
        }
        else if(c == '&' || c == '|') {
            if(!ops.empty() && ops.top() != '+' && ops.top() != '*') {
                calc(nums, ops);
            }
            ops.push(c);
        }
        else if(c == '*') {
            if(!ops.empty() && ops.top() != '+') {
                calc(nums, ops);      
            }
            ops.push(c);
        }
        else if(c == '+') {
            if(!ops.empty()) {
                calc(nums, ops);
            }
            ops.push(c);
        }
        i++;
    }

    while(!ops.empty()) {
        calc(nums, ops);
    }

    return nums.top();

}
