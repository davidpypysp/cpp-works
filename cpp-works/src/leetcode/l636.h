#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <sstream>
using namespace std;

class L636 {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> result(n);
        stack<int> st;
        int prev = 0;
        for(string log : logs) {
            stringstream ss(log);
            string s1, s2 ,s3;
            getline(ss, s1, ':');
            getline(ss, s2, ':');
            getline(ss, s3, ':');
            int id = stoi(s1);
            int time = stoi(s3);
            if(s2 == "start") {
                if(!st.empty()) result[st.top()] += time - prev;
                st.push(id);
                prev = time;
            }
            else {
                result[st.top()] += time - prev + 1;
                st.pop();
                prev = time + 1;
            }
        }
        return result;
    }
};