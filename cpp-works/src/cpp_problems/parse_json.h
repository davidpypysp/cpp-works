#include <iostream>
#include <string>
using namespace std;

string space(int num) {
    string result;
    for(int i = 0; i < num; i++) result += ' ';
    return result;
}

string ParseJson(string s) {
    int indent = 0;
    string result;
    for(int i = 0; i < s.size(); i++) {
        char c = s[i];
        if(c == '[' || c == '{') {
            result += c;
            indent += 2;
            result += '\n';
            result += space(indent);
        }
        else if(c == ']' || c == '}') {
            indent -= 2;
            result += '\n';
            result += space(indent) + c;
        }
        else if(c == ',') {
            result += c;
            result += '\n';
            result += space(indent);
        }
        else if(c == ' ') {
            continue;
        }
        else if(c == ':') {
            result += c;
            result += ' ';
        }
        else {
            result += c;
        }
    }
    return result;
}
