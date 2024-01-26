#include <iostream>
#include "BigInt.h"

int main() {

    //testing

    BigInt b = 10;
    BigInt a = 10000;
    BigInt c;

    c = a - b;
    a -= b;
    cout << "a -= b " << endl;
    cout << "c " << c << endl;

    c = a + b;
    a += b;

    cout << "a += b " << a << endl;
    cout << "c " << c << endl;
    bool is = b > a;
    cout << is << endl;

    return 0;
}
