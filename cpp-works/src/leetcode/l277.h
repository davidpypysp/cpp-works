#include <iostream>
#include <stdlib.h>
using namespace std;

// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        bool vis[n];
        memset(vis, false, sizeof(vis));
        int a = 0, prev = -1;
        int cnt = 0;
        while (cnt < n) {
            vis[a] = true;
            bool know_new = false;
            for(int b = 0; b < n; b++) {
                if(b == a) continue;
                if(!vis[b] && knows(a, b)) {
                    know_new = true;
                    prev = a;
                    a = b;
                    cnt++;
                    break;
                }
            }
            if(!know_new) {
                for(int i = 0; i < n; i++) {
                    if(i == a || !vis[i]) continue;
                    if(knows(a, i)) return -1;
                }
                for(int i = 0; i < n; i++) {
                    if(i == prev || i == a) continue;
                    if(!knows(i, a)) return -1;
                }
                return a;
            }
        }
        return -1;
    }
};