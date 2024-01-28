//
// Created by Drew Goldstein on 1/24/24.
//
// with the help of https://www.geeksforgeeks.org/bigint-big-integers-in-c-with-example/#
#include <string>
#include "BigInt.h"
#include <iostream>
using namespace std;


// To display BigInt objects to the console
ostream &operator<<(ostream &c, const BigInt &b) {
    int s = b.digits.size();

    for(int i = s - 1; i >= 0; i--){
        cout << (int)b.digits[i];
    }
    return cout;
}

//these constructors take in large numbers and convert them to BigInt objects
// For all the constructors, I am reading the number passed in backwards
// ex. BigInt b = "123456789" will give b.digits = "987654321" (in unicode)

BigInt::BigInt(unsigned long long num) {
    digits = "";
    do{
        digits.push_back((num % 10));
        num /= 10;
    }while(num > 0);
}

BigInt::BigInt(string &str) {
    digits = "";
    int s = str.size();
    for (int i = s-1; i >=0; i++){
        digits.push_back(str[i]);
    }
}

BigInt::BigInt(const char *c) {
    digits = "";
    int s = strlen(c);
    for(int i = s-1; i >= 0; i--){
        digits.push_back(c[i]);
    }
}

BigInt::BigInt(BigInt &b) { digits = b.digits; }

bool operator>(const BigInt &first, const BigInt &second) {

    int f = first.digits.size();
    int s = second.digits.size();

    // if BigInt objects are not the same size,
    //returns true if first is bigger, returns false if second is bigger
    if ( f != s){ return (f > s); }

    // if they are the same size, compare each digit
    for(int i = s-1; i >= 0; i--){
        if(first.digits[i] != second.digits[i]){ return (first.digits[i] > second.digits[i]);}
    }
    return false;
}

bool operator<(const BigInt& first,const BigInt& second){
    // utilizing > operator that I already wrote
    return second > first;
}

BigInt &operator+=(BigInt &first, const BigInt &second) {
    int carry = 0;
    int add;

    int f = first.digits.size();
    int s = second.digits.size();

    int diff = s - min(f,s);
    //cout << "first is ... " << first << endl;

    //if they are different sizes, add zeroes to the front of the first BigInt to make adding easier
    if (diff){
        first.digits.append(diff,0);
        //cout << "first is " << first << endl;
        f = first.digits.size();
    }

    for (int i = 0; i < f; i++){
        // adding digits, carrying an extra digit to add to the next higher order of magnitude
        if(i < s){ add = first.digits[i] + second.digits[i] + carry; }
        else{ add = first.digits[i] + carry; }
        first.digits[i] = add % 10;
        carry = add / 10;
    }

    // extra carried digit to front of BigInt object
    if(carry > 0){ first.digits.push_back(carry); }

    return first;
}

const BigInt operator+(const BigInt &first, const BigInt &second) {

    //utilizing += operator written above
    BigInt dummy;
    dummy = first;
    dummy += second;
    return dummy;
}

// pre-increment
BigInt BigInt::operator++() {
    *this += 1;
    return *this;
}
// post-increment
BigInt BigInt::operator++(int dummy) {
    BigInt temp;
    temp = *this;
    *this += 1;
    return temp;
}

BigInt &operator-=(BigInt &first, const BigInt &second) {
    int carry = 0;
    int sub;
    int f = first.digits.size();
    int s = second.digits.size();
    int counter = f-1;

    if (first < second){throw("NEGATIVE");}

    for(int i = 0; i < f ; i++){
        if(i < s){ sub = first.digits[i] - second.digits[i] - carry; }
        else{ sub = first.digits[i] - carry; }

        if (sub < 0 ){
            // if the subtraction leads to a negative digit,
            // make the current digit positive and use carry
            // to subtract from the next digit up
            sub += 10;
            carry = 1;
        }
        else{
            carry = 0;
        }
        first.digits[i] = sub;
    }

    // removing leading zeroes in front of BigInt
    while(counter && !first.digits[counter] ){
        first.digits.pop_back();
        counter--;
    }
    return first;
}

const BigInt operator-(const BigInt &first, const BigInt &second) {
    //utilizing -= operator written above
    BigInt dummy;
    dummy = first;
    dummy -= second;
    return dummy;
}


//pre-increment
BigInt BigInt::operator--() {
    *this -= 1;
    return *this;
}
 //post-increment
BigInt BigInt::operator--(int dummy) {
    BigInt temp;
    temp = *this;
    *this -= 1;
    return temp;
}

const BigInt operator*(const BigInt &first, const BigInt &second) {
    return BigInt();
}

const BigInt operator/(const BigInt &first, const BigInt &second) {
    return BigInt();
}



//int &BigInt::operator[](const int i) const {
//    return <#initializer#>;
//}











