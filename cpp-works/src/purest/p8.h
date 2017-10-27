#include <vector>
#include <unordered_set>
#include <stack>
#include <string>
using namespace std;

int checkSequence(vector<string> events){
    if(events.size() == 0) return 0;
    stack<string> stack;
    unordered_set<string> set;
    for (int i = 0; i < events.size(); i++) {
        int pos = events[i].find(" ");
        string s1 = events[i].substr(0, pos);
        string s2 = events[i].substr(pos+1);
        if (s1 == "AQUIRE") {
            if (set.find(s2) != set.end()) return i + 1;
            set.insert(s2);
            stack.push(s2);
        } 
        else {
        	if (stack.empty() || stack.top() != s2) return i + 1;
            set.erase(s2);
            stack.pop();
        }
    }
    if (!stack.empty()) return events.size() + 1;
	return 0;
}