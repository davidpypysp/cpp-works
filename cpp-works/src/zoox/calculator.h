#include <iostream>
#include <stack>

using namespace std;

bool is_digit(char c) {
    return c >= '0' && c <= '9';
}

int calc(stack<int> &nums, stack<char> &ops) {
    int val2 = nums.top();
    nums.pop();
    int val1 = nums.top();
    nums.pop();
    char op = ops.top();
    ops.pop();
    if(op == '+') return val1 + val2;
    else return val1 * val2;
}

int calculator(string s) {
    int result = 0;
    int n = s.size();

    stack<int> nums;
    stack<char> ops;

    for(int i = 0; i < n; i++) {
        char c = s[i];
        if(is_digit(c)) {
            string num_str;
            num_str += c;
            while( i+1 < n && is_digit(s[i+1]) ) num_str += s[++i];
            int val = stoi(num_str);
            nums.push(val);
        }

        else if(c == '+') {
            while(!ops.empty()) {
                int val = calc(nums, ops);
                nums.push(val);
            }
            ops.push(c);
        }
        else if(c == '*') {
            while(!ops.empty() && ops.top() == '*') {
                int val = calc(nums, ops);
                nums.push(val);
            }
            ops.push(c);
        }
    }

    while(!ops.empty()) {
        int val = calc(nums, ops);
        nums.push(val);
    }
    return nums.top();
}
