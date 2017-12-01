#include <iostream>  
using namespace std;  
  
class Date {
private:
    int mo, da, yr;  
public:  
    Date(int m, int d, int y) {  
        mo = m; da = d; yr = y;  
    }  
    friend ostream& operator << (ostream& os, const Date& dt) {
        os << dt.mo << '/' << dt.da << '/' << dt.yr;  
        return os;  
    }
}; 



  
void t4() {  
    Date dt(5, 6, 92); 
    Date dt2(2, 4, 5); 
    cout << dt;  
    cout << dt << dt2;
    cout << "end" << endl;
}  

/*
friend ostream& operator << (ostream& out, const Obj& myObj);

1. This line might appear in a Class definition.
    It's for output the Object information into the ostream like "cout << myObj;"
2. We may need to deal with cout << myObj1 << myObj2; 
    So when finish cout << myObj1 first, we return cout reference.
    And then we could deal with cout << myObj2.
3. ostream& operator << (ostream& out) will take 'this' pointer as the first argument, 'out' as second,
    so it just can be used as "myObj << out"" which is not we want
*/
