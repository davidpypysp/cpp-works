#include <vector>
#include <iostream>
using namespace std;

class L396 {
public:
    int maxRotateFunction(vector<int>& A) {
        int sum = 0, next = 0;
        for(int i = 0; i < A.size(); i++) {
            sum += A[i];
            next += i * A[i];
        }
        int max_val = next;
        for(int i = A.size()-1; i > 0; i--) {
            next += sum - A.size() * A[i];
            max_val = max(max_val, next);
        }
        return max_val;
    }
};