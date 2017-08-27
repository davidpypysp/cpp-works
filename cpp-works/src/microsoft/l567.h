#include <iostream>
#include <vector>
using namespace std;

class L567 {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> cnts1(26), cnts2(26);
        int n1 = s1.size(), n2 = s2.size();
        for(int i = 0; i < n1; i++) {
            cnts1[s1[i] - 'a']++;
            cnts2[s2[i] - 'a']++;
        }
        if(cnts1 == cnts2) return true;
        for(int i = n1; i < n2; i++) {
            cnts2[s2[i-n1] - 'a']--;
            cnts2[s2[i] - 'a']++;
            if(cnts1 == cnts2) return true;
        }
        return false;
    }
};