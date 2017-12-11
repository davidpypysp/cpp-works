#include <iostream>
#include <stdlib.h>

using namespace std;

int C1() {
    double foo = 4.0;
    const double &&bar = std::move(foo);
    cout << foo << endl;
    cout << bar << endl;
}
