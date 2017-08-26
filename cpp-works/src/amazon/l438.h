#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;


class L438 {
public:
    vector<int> findAnagrams(string s, string p) {
        int p_cnts[26];
        memset(p_cnts, 0, sizeof(p_cnts));
        for(int i = 0; i < p.size(); i++) 
            p_cnts[p[i] - 'a']++;
        
        vector<int> result;
        
        int left = 0, right = 0;
        int match_cnts[26];
        memset(match_cnts, 0, sizeof(match_cnts));
        while(right < s.size()) {
            int c = s[right] - 'a';
            if(!p_cnts[c]) {
                right++;
                left = right;
            }
            
            else {
                if(match_cnts[c] < p_cnts[c]) {
                    match_cnts[c]++;
                    if(right - left + 1 == p.size()) {
                        result.push_back(left);
                        match_cnts[s[left] - 'a']--;
                        left++;
                    }
                }
                else {
                    while((s[left]-'a') != c) {
                        match_cnts[s[left] - 'a']--;
                        left++;
                    }
                    left++;
                }
                right++;
            }
        }
        return result;
    }
};