//
//  f.hpp
//  task3
//
//  Created by Дарья Землянская on 31.10.2020.
//  Copyright © 2020 Дарья Землянская. All rights reserved.
//

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <exception>

class MyException: public std::exception{
public:
    MyException(std::string error)
        : m_error(error)
    {
    }
    const char* what() const noexcept override { return m_error.c_str(); }
private:
    std::string m_error;
};




class Fraction{
public:
    
    Fraction(int x = 1, int y = 1): m_num(x), m_den(y){
        if(m_den == 0){
            throw (MyException("Div Null"));
        }
        reduce();
    }
    Fraction(const std::string &string);
    ~Fraction() = default;
    
    const auto getNumerator() const {return m_num;};
    const auto getDenominator() const {return m_den;};
    
    explicit operator float() const{return (m_num*1.0)/(m_den*1.0);};
    
    Fraction& operator+= (const Fraction& frac);
    Fraction& operator-= (const Fraction& frac);
    Fraction& operator*= (const Fraction& frac);
    Fraction& operator/= (const Fraction& frac);
    
    friend bool operator== (const Fraction &farc1, const Fraction &frac2);
    friend bool operator!= (const Fraction &frac1, const Fraction &frac2);
    
    friend bool operator> (const Fraction &frac1, const Fraction &frac2);
    friend bool operator<= (const Fraction &frac1, const Fraction &frac2);
    
    friend bool operator< (const Fraction &frac1, const Fraction &frac2);
    friend bool operator>= (const Fraction &frac1, const Fraction &frac2);
    
    Fraction& operator++();
    Fraction operator ++(int);
    Fraction& operator--();
    Fraction operator--(int);
    
    friend std::ostream& operator<< (std::ostream &os, const Fraction &frac);
    friend std::istream& operator>> (std::istream &in, Fraction &frac);
    
private:
    int m_num;
    int m_den;
    
    void reduce();
};

int gcd(int a, int b);
int lcm(int a, int b);
Fraction operator*(const Fraction &frac1, const Fraction &frac2);
Fraction operator/(const Fraction &frac1, const Fraction &frac2);
Fraction operator-(const Fraction &frac1, const Fraction &frac2);
Fraction operator+(const Fraction &frac1, const Fraction &frac2);

