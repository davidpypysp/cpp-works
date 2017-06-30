#include <iostream>
#include <string.h>

using namespace std;

class C8_5 {
public:
    static void printPar(int count) {
        printPar("", 0, 0, count);
    }

    static void printPar(string str, int l, int r, int count) {

        if(l == count && r == count) {
            cout << str << endl;
            return;
        }

        if(l < count) {
            printPar(str + "(", l+1, r, count);
        }
        if(r < l) {
            printPar(str + ")", l, r+1, count);
        }
    }

};