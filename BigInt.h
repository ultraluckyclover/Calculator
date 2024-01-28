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
    BigInt(std::string &str);
    BigInt(const char *c);
    BigInt(BigInt& big);

    //int &operator[](const int i) const;

    //operators
    friend const BigInt operator+(const BigInt& first, const BigInt& second);
    friend BigInt &operator+=(BigInt& first, const BigInt& second);
    BigInt operator++();
    BigInt operator++(int dummy);

    friend const BigInt operator-(const BigInt& first, const BigInt& second);
    friend BigInt &operator-=(BigInt& first, const BigInt& second);
    BigInt operator--();
    BigInt operator--(int dummy);

    friend const BigInt operator*(const BigInt& first, const BigInt& second);
    friend const BigInt operator/(const BigInt& first, const BigInt& second);

    friend ostream &operator<<(ostream& c, const BigInt& b);

    friend bool operator>(const BigInt& first,const BigInt& second);
    friend bool operator<(const BigInt& first,const BigInt& second);

};

#endif //CALCULATOR_BIGINT_H
