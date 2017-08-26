#include <iostream>
#include <stack>
using namespace std;


class L20 {
public:
    bool isValid(string s) {
        std::stack<char> st;
        for(int i = 0; i < s.size(); i++) {
            char c = s[i];
            if(c == '(' || c == '[' || c == '{') st.push(c);
            else if(c == ')') {
                if(st.empty() || st.top() != '(') return false;
                st.pop();
            }
            else if(c == ']') {
                if(st.empty() || st.top() != '[') return false;
                st.pop();
            }
            else if(c == '}') {
                if(st.empty() || st.top() != '{') return false;
                st.pop();
            }
        }
        return st.empty();
    }
};