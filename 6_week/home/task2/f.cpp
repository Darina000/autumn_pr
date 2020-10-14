//  Created by Дарья Землянская on 15.10.2020.
//  Copyright © 2020 Дарья Землянская. All rights reserved.
//
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

#include "f.hpp"



std::ostream& operator<< (std::ostream &os, const Frac &frac){
    os << "------" << std::endl;
    os << "Numerator: ";
    os << frac.num << " ";
    os << std::endl;
    os << "Denominator : ";
    os << frac.den  << std::endl;
    os << "------" << std::endl;
    return os;
};

std::istream& operator>> (std::istream &in, Frac &frac)
{
    in >> frac.num;
    in >> frac.den;
 
    return in;
}

int gcd(int a, int b) {
    if (a == b){
        return a;
    }
    while (b > 0) {
        int c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int lcm(int a, int b) {
    return gcd(a, b) * a * b;
}

void Frac::reduce() {
    int gc = gcd(abs(num), den);
    if (gc != 1) {
        num = num / gc;
        den = den/ gc;
    }
}


Frac operator*(const Frac &frac1, const Frac &frac2) {
    int num_res = frac1.getNumerator() * frac2.getNumerator();
    int den_res = frac1.getDenominator() * frac2.getDenominator();
    Frac res(num_res, den_res);
    res.reduce();
    std::cout << "*" << std::endl;
    std::cout << res << std::endl;
    return res;
}

Frac operator/(const Frac &frac1, const Frac &frac2) {
    int num_res = frac1.getNumerator() * frac2.getDenominator();
    int den_res = frac1.getDenominator() * frac2.getNumerator();
    Frac res(num_res, den_res);
    res.reduce();
    std::cout << "/" << std::endl;
    std::cout << res << std::endl;
    return res;
}

Frac operator-(const Frac &frac1, const Frac &frac2) {
    int num_res = frac1.getNumerator() * frac2.getDenominator() - frac1.getDenominator() * frac2.getNumerator();
    int den_res = lcm(frac1.getDenominator(), frac2.getDenominator());
    Frac res(num_res, den_res);
    res.reduce();
    std::cout << "-" << std::endl;
    std::cout << res << std::endl;
    return res;
}

Frac operator+(const Frac &frac1, const Frac &frac2) {
    int num_res = frac1.getNumerator() * frac2.getDenominator() + frac1.getDenominator() * frac2.getNumerator();
    int den_res = lcm(frac1.getDenominator(), frac2.getDenominator());
    Frac res(num_res, den_res);
    res.reduce();
    std::cout << "+" << std::endl;
    std::cout << res << std::endl;
    return res;
}

bool operator== (const Frac &frac1, const Frac &frac2)
{
    return (frac1.getNumerator() * frac2.getDenominator() == frac1.getDenominator() * frac2.getNumerator());
}

bool operator!= (const Frac &frac1, const Frac &frac2)
{
    return !(frac1.getNumerator() * frac2.getDenominator() == frac1.getDenominator() * frac2.getNumerator());
}

bool operator> (const Frac &frac1, const Frac &frac2)
{
    return (frac1.getNumerator() * frac2.getDenominator() > frac1.getDenominator() * frac2.getNumerator());
}
 
bool operator>= (const Frac &frac1, const Frac &frac2)
{
    return (frac1.getNumerator() * frac2.getDenominator() >= frac1.getDenominator() * frac2.getNumerator());
}
 
bool operator< (const Frac &frac1, const Frac &frac2)
{
    return  (frac1.getNumerator() * frac2.getDenominator() < frac1.getDenominator() * frac2.getNumerator());
}
 
bool operator<= (const Frac &frac1, const Frac &frac2)
{
    return  (frac1.getNumerator() * frac2.getDenominator() <= frac1.getDenominator() * frac2.getNumerator());
}

Frac& Frac::operator++()
{
    num += den;
    std::cout << "++" << std::endl;
    std::cout << *this << std::endl;
    return *this;
}
 
Frac& Frac::operator--()
{
    num -= den;
    std::cout << "--" << std::endl;
    std::cout << *this << std::endl;
    return *this;
}

Frac& Frac::operator+= (Frac const& frac) {
    num = num * frac.getDenominator() + den * frac.getNumerator();
    den = lcm((den), frac.getDenominator());
    reduce();
    std::cout << "+=" << std::endl;
   std::cout << *this << std::endl;
  return *this;
}
Frac& Frac::operator-= (Frac const& frac) {
    num = num * frac.getDenominator() - den * frac.getNumerator();
    den = lcm((den), frac.getDenominator());
    reduce();
    std::cout << "-=" << std::endl;
    std::cout << *this << std::endl;
  return *this;
}

Frac& Frac::operator*= (Frac const& frac) {
    num = num * frac.getNumerator();
    den = den * frac.getDenominator();
    reduce();
    std::cout << "*=" << std::endl;
    std::cout << *this << std::endl;
    return *this;
}
Frac& Frac::operator/= (Frac const& frac) {
    num = num * frac.getDenominator();
    den = den * frac.getNumerator();
    reduce();
    std::cout << "/=" << std::endl;
    std::cout << *this << std::endl;
    return *this;
}

double Frac::To_Float(){
    double a = (num*1.0)/(den*1.0);
    std::cout << "Float "  << a << std::endl;
    return a;
};
