//  Created by Дарья Землянская on 31.10.2020.
//  Copyright © 2020 Дарья Землянская. All rights reserved.
//

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>

#include "f.hpp"



std::ostream& operator<< (std::ostream &os, const Fraction &fraction){
    
    os << "------" << std::endl;
    os << "Numerator: ";
    os << fraction.m_num << " ";
    os << std::endl;
    
    
    os << "Denominator : ";
    os << fraction.m_den  << std::endl;
    os << "------" << std::endl;
    return os;
};

std::istream& operator>> (std::istream &in, Fraction &fraction)
{
    char i;
    in >> fraction.m_num >> i >> fraction.m_den;
    if (fraction.m_den == 0){
        while (fraction.m_den == 0){
            std::cout << "Dev NULL, enter correctly" << std::endl;
            in >> fraction.m_num >> i >> fraction.m_den;
        }
        std::cout << "Devddddde" << std::endl;
    }
    fraction.reduce();
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


void Fraction::reduce() {
    int gc = gcd(abs(m_num), m_den);
    if ((gc != 1)&& m_den != 0) {
        m_num = m_num / gc;
        m_den = m_den/ gc;
    }
}

Fraction operator*(const Fraction &frac1, const Fraction &frac2) {
    int num_res = frac1.getNumerator() * frac2.getNumerator();
    int den_res = frac1.getDenominator() * frac2.getDenominator();
    Fraction res(num_res, den_res);
    return res;
}

Fraction operator/(const Fraction &frac1, const Fraction &frac2) {
    if (frac1.getDenominator() == 0){
        throw (MyException("Dev NULL: first fraction"));
    }
    if (frac2.getDenominator() == 0){
        throw (MyException("Dev NULL: second fraction"));
    }
    int num_res = frac1.getNumerator() * frac2.getDenominator();
    int den_res = frac1.getDenominator() * frac2.getNumerator();
    Fraction res(num_res, den_res);
    return res;
}

Fraction operator-(const Fraction &frac1, const Fraction &frac2) {
    int num_res = frac1.getNumerator() * frac2.getDenominator() - frac1.getDenominator() * frac2.getNumerator();
    int den_res = lcm(frac1.getDenominator(), frac2.getDenominator());
    Fraction res(num_res, den_res);
    return res;
}

Fraction operator+(const Fraction &frac1, const Fraction &frac2) {
    int num_res = frac1.getNumerator() * frac2.getDenominator() + frac1.getDenominator() * frac2.getNumerator();
    int den_res = lcm(frac1.getDenominator(), frac2.getDenominator());
    Fraction res(num_res, den_res);
    return res;
}

bool operator== (const Fraction &frac1, const Fraction &frac2)
{
    return !(frac1 < frac2) && !(frac2 < frac1);
}
bool operator!= (const Fraction &frac1, const Fraction &frac2)
{
    return !(frac1 == frac1);
}
bool operator> (const Fraction &frac1, const Fraction &frac2)
{
    return (frac1.getNumerator() * frac2.getDenominator() > frac1.getDenominator() * frac2.getNumerator());
}
 
bool operator>= (const Fraction &frac1, const Fraction &frac2)
{
    return (frac1.getNumerator() * frac2.getDenominator() >= frac1.getDenominator() * frac2.getNumerator());
}
 
bool operator< (const Fraction &frac1, const Fraction &frac2)
{
    return  (frac1 > frac2);
}
 
bool operator<= (const Fraction &frac1, const Fraction &frac2)
{
    return  (frac1 >= frac2);
}

Fraction& Fraction::operator++()
{
    m_num += m_den;
    reduce();
    return *this;
}
Fraction Fraction::operator ++(int)
{
    Fraction temp(m_num);
    ++(*this);
    return temp;
}
 
Fraction& Fraction::operator--()
{
    m_num -= m_den;
    reduce();
    return *this;
}
Fraction Fraction::operator --(int)
{
    Fraction temp(m_num);
    --(*this);
    return temp;
}

Fraction& Fraction::operator+= (Fraction const& frac) {
    m_num = m_num * frac.getDenominator() + m_den * frac.getNumerator();
    m_den = lcm((m_den), frac.getDenominator());
    reduce();
  return *this;
}
Fraction& Fraction::operator-= (Fraction const& frac) {
    m_num = m_num * frac.getDenominator() - m_den * frac.getNumerator();
    m_den = lcm((m_den), frac.getDenominator());
    reduce();
  return *this;
}

Fraction& Fraction::operator*= (Fraction const& frac) {
    m_num *= frac.getNumerator();
    m_den *= frac.getDenominator();
    reduce();
    return *this;
}
Fraction& Fraction::operator/= (Fraction const& frac) {
    m_num *=  frac.getDenominator();
    m_den *=  frac.getNumerator();
    reduce();
    return *this;
}
