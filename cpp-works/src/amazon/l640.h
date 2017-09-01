#include <iostream>
#include <stdio.h>

using namespace std;

class L640 {
public:
    string solveEquation(string equation) {
        int index = 0;
        int k1 = 0, b1 = 0;
        search(equation, index, k1, b1);
        int k2 = 0, b2 = 0;
        search(equation, index, k2, b2);
        int k = k1 - k2, b = b2 - b1;
        if(k == 0) {
            if(b == 0) return "Infinite solutions";
            else return "No solutions";
        }
        b /= k;
        return "x=" + to_string(b);
    }
    
    void search(string &equation, int &index, int &k, int &b) {
        string s = "";
        int i = index;
        while(i < equation.size() && equation[i] != '=') {
            
            if(equation[i] == 'x') {
                if(s.size() == 0 || s == "+") k += 1;
                else if(s == "-") k += -1;
                else {
                    int val = stoi(s);
                    k += val;
                }
                s = "";
                if(isOp(equation[i+1])) {
                    s.push_back(equation[++i]);
                }
                i++;
                
            }
            else if(isOp(equation[i]) && i != index) {
                int val = stoi(s);
                b += val;
                s = "";
                s.push_back(equation[i++]);
            }
            else {
                s.push_back(equation[i++]);
            }
        }
        if(s.size() > 0) {
            b += stoi(s);
        }
        index = i+1;
    }
    
    bool isOp(char c) {
        return c == '+' || c == '-';
    }
    
    bool isNum(char c) {
        return c >= '0' && c <='9';
    }
};