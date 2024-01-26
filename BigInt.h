//
// Created by Drew Goldstein on 1/24/24.
//

#ifndef CALCULATOR_BIGINT_H
#define CALCULATOR_BIGINT_H

#include <iostream>
using namespace std;

class BigInt {
    std::string digits;
public:
    //constructors
    BigInt(unsigned long long num = 0);
    BigInt(std::string &);
    BigInt(const char *);
    BigInt(BigInt &);

    //operators
    friend const BigInt operator+(const BigInt& first, const BigInt& second);
    friend BigInt &operator+=(BigInt& first, const BigInt& second);

    friend const BigInt operator-(const BigInt& first, const BigInt& second);
    friend BigInt &operator-=(BigInt& first, const BigInt& second);

    friend const BigInt operator*(const BigInt& first, const BigInt& second);
    friend const BigInt operator/(const BigInt& first, const BigInt& second);

    friend ostream &operator<<(ostream &, const BigInt &);

    friend bool operator>(const BigInt& first,const BigInt& second);
    friend bool operator<(const BigInt& first,const BigInt& second);

};

#endif //CALCULATOR_BIGINT_H
