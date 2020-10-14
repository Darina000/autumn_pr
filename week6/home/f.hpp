//  Created by Дарья Землянская on 15.10.2020.
//  Copyright © 2020 Дарья Землянская. All rights reserved.
//

#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>



class Frac{
public:
    Frac(signed int x=1.0, int y=1.0): num(x), den(y)
    {}
    ~Frac(){
    };
    
    const auto getNumerator() const {return num;};
    const auto getDenominator() const {return den;};
    
    double To_Float();
    // fraction reduction
    void reduce();
    
    Frac& operator+= (Frac const& frac);
    Frac& operator-= (Frac const& frac);
    Frac& operator*= (Frac const& frac);
    Frac& operator/= (Frac const& frac);
    
    friend bool operator== (const Frac &c1, const Frac &c2);
    friend bool operator!= (const Frac &c1, const Frac &c2);
    
    friend bool operator> (const Frac &d1, const Frac &d2);
    friend bool operator<= (const Frac &d1, const Frac &d2);
    
    friend bool operator< (const Frac &d1, const Frac &d2);
    friend bool operator>= (const Frac &d1, const Frac &d2);
    
    Frac& operator++();
    Frac& operator--();
    
    friend std::ostream& operator<< (std::ostream &os, const Frac &frac);
    friend std::istream& operator>> (std::istream &in, Frac &frac);
    
private:
    signed int num;
    int den;
};

int gcd(int a, int b);
int lcm(int a, int b);
Frac operator*(const Frac &frac1, const Frac &frac2);
Frac operator/(const Frac &frac1, const Frac &frac2);
Frac operator-(const Frac &frac1, const Frac &frac2);
Frac operator+(const Frac &frac1, const Frac &frac2);

