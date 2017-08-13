#include <iostream>
#include <stdio.h>

using namespace std;

class BitSet {
public:
    int size;
    int *array;
    BitSet(int size) : size(size) {
        array = new int[(size + 32) >> 5];
    }

    void set(int pos) {
        int base = pos >> 5;
        int mod = pos & 0x1F;
        array[base] |= 1 << mod;

    }

    bool get(int pos) {
        int base = pos >> 5;
        int mod = pos & 0x1F;
        return (array[base] & (1 << mod)) != 0;
    }


};


class C11_4 {

public:
    void PrintDuplicate(int array[], int size) {
        BitSet bitset(32000);
        for(int i = 0; i < size; i++) {
            int num = array[i];
            int num0 = num-1;
            if(!bitset.get(num0)) {
                bitset.set(num0);
            } 
            else {
                cout << num << " ";
            }
        }
        cout << endl;
    }



};