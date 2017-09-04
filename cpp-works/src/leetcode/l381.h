#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class RandomizedCollection {
public:
    vector<pair<int, int>> list;
    unordered_map<int, vector<int>> map;
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        if(map.find(val) == map.end()) {
            vector<int> v;
            v.push_back(list.size());
            map[val] = v;
            list.push_back(make_pair(val, 0));
            return true;
        }
        else {
            map[val].push_back(list.size());
            list.push_back(make_pair(val, map[val].size()-1));
            return false;
        }
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if(map.find(val) != map.end()) {
            int index = map[val].back();
            map[val].pop_back();
            if(map[val].size() == 0) map.erase(val);
            if(index != list.size()-1) {
                list[index] = list.back();
                map[list[index].first][list[index].second] = index;
            }
            list.pop_back();
            return true;
        }
        return false;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        int index = rand() % list.size();
        return list[index].first;
    }
};
