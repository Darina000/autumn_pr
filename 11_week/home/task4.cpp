//  Created by Дарья Землянская on 16.11.2020.
//  Copyright © 2020 Дарья Землянская. All rights reserved.
//


#include <type_traits>
#include <iostream>

template<bool B, typename T = void>
struct enable_if {};
 
template<typename T>
struct enable_if<true, T> { using type = T;};

//псевдоним
template <typename T>
using is_integral = typename std::is_integral<T>;

//варианты использования enable_if
// тип возврата (bool) допустим, если T - целочисленный тип:


template <typename T>
typename enable_if<is_integral<T>::value,bool>::type
  is_odd (T i) {return bool(i%2);}

//псевдоним
template<typename T>
using enable_if_t = typename enable_if<is_integral<T>::value>::type;

// второй аргумент шаблона действителен, если T является целочисленным типом
template < typename T, typename = enable_if_t<T>>
bool is_even (T i) {return !bool(i%2);} //отрицание bool


int main()
{
    short int i = 1.8;  // не компилируется, если тип не целочисленный

    std::cout << std::boolalpha;
    std::cout << "i is odd: " << is_odd(i) << std::endl;
    std::cout << "i is even: " << is_even(i) << std::endl;
    
    return 0;
}
