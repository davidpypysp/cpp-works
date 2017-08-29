#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

struct UnionSet2 {
    int size;
    vector<int> set;
    UnionSet2(int size) : size(size) {
        for(int i = 0; i < size; i++) {
            set.push_back(i);
        }
    }
    
    int Find(int index) {
        if(index != set[index]) set[index] = Find(set[index]);
        return set[index];
    }
    
    void Union(int index1, int index2) {
        int p1 = Find(index1);
        int p2 = Find(index2);
        set[p2] = p1;
    }
    
    bool Connected(int index1, int index2) {
        return Find(index1) == Find(index2);
    }
    
    
};


class L305 {
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        int grid[m][n];
        UnionSet2 us(m * n);
        int result = 0;
        vector<int> results;
        for(int i = 0; i < positions.size(); i++) {
            int y = positions[i].first, x = positions[i].second;
            grid[y][x] = true;
            int index = y * m + x;
            unordered_set<int> set;
            if(y - 1 >= 0 && grid[y-1][x]) {
                set.insert(us.Find(index - n));
                us.Union(index - n, index);
            }
            if(x - 1 >= 0 && grid[y][x-1]) {
                set.insert(us.Find(index - 1));
                us.Union(index-1, index);
            }
            if(y + 1 < m && grid[y+1][x]) {
                set.insert(us.Find(index + n));
                us.Union(index + n, index);
            }
            if(x + 1 < n && grid[y][x+1]) {
                set.insert(us.Find(index + 1));
                us.Union(index + 1, index);
            }
            result += 1 - set.size();
            results.push_back(result);
            
        }
        return results;
    }
};  