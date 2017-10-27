#include <iostream>
#include <queue>
using namespace std;

// Forward declaration of the read4 API.
int read4(char *buf);

class L158 {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int cnt = 0;
        while(q.empty() == false && n > 0) {
            buf[cnt++] = q.front();
            q.pop();
            n--;
        }
        
        while(n > 0) {
            char tmp[4];
            int m = read4(tmp);
            if(n < m) {
                for(int i = n; i < m; i++) {
                    q.push(tmp[i]);
                }
            }
            int len = min(m, n);
            for(int i = 0; i < len; i++) {
                buf[cnt++] = tmp[i];
            }
            if(len < 4) break;
            n -= len;
        }
        return cnt;
    }
    
    queue<char> q;
};