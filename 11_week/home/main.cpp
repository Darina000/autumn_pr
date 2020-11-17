//  Created by Дарья Землянская on 16.11.2020.
//  Copyright © 2020 Дарья Землянская. All rights reserved.
//

#include <type_traits>
#include <new>
#include <iostream>
#include <string>

template<bool B, class T = void>
struct enable_if {};
 
template<class T>
struct enable_if<true, T> { typedef T type; };

// тип возврата (bool) допустим, если T - целочисленный тип:
template <class T>
typename enable_if<std::is_integral<T>::value,bool>::type
  is_odd (T i) {return bool(i%2);}

// второй аргумент шаблона действителен, если T является целочисленным типом
template < class T, class = typename enable_if<std::is_integral<T>::value>::type>
bool is_even (T i) {return !bool(i%2);}


int main()
{
    short int i = 1.8;  // не компилируется, если тип не целочисленный

    std::cout << std::boolalpha;
    std::cout << "i is odd: " << is_odd(i) << std::endl;
    std::cout << "i is even: " << is_even(i) << std::endl;
    
    return 0;
}
