// After running this program, my conclusion is :
// - References really are aliases for variables, since they have 
//   the same address.
// - References seem to actually be implemented as pointers, but they have
//   specific semantics in the language, such that they can be treated as if
//   they were regular value of their original type.

#include <iostream>

using namespace std;

void intswap(int &a, int &b) {
    int c;
    c = a;
    a = b;
    b = c;
}

int main(int argc, char *argv[]) {
    int a=42, b=13;
    intswap(a, b);
    cout << a << ", " << b << endl; // 13, 42
    int &ref = a;
    a = 100;
    cout << a << endl;    // 100
    cout << ref << endl;  // 100
    cout << &a << endl;   // 0x7ffe92a5dc00
    cout << &ref << endl; // 0x7ffe92a5dc00
    int *ptr = &a;
    int &pref = *ptr;
    a = 200;
    cout << a << endl;    // 200
    cout << pref << endl; // 200
    int &refref = ref;
    ref = a;
    return 0;
}
