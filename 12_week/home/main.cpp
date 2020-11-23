//  Created by Дарья Землянская on 23.11.2020.
//  Copyright © 2020 Дарья Землянская. All rights reserved.
//

#include <iostream>
#include <type_traits>



template < auto n>
struct Fibonacci
{
    static const decltype(n) value = Fibonacci<n - 2 >::value + Fibonacci < n - 1 >::value;
};
template <>
struct Fibonacci <1>
{
    static const int value = 1;
};
template <>
struct Fibonacci <0>
{
    static const int value = 0;
};

int main()
{
    std::cout << Fibonacci<8>::value << std::endl;
    
    return 0;
}
