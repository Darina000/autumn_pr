//  Created by Дарья Землянская on 23.11.2020.
//  Copyright © 2020 Дарья Землянская. All rights reserved.
//

#include <iostream>
#include <type_traits>

template < auto n >
struct Factorial
{
    static const decltype(n) value = n * Factorial < n - 1 > ::value;
};

template <>
struct Factorial < 0 >
{
    static const int value = 1;
};

template < auto n, auto k >
struct BinominalK
{
    static const decltype(n) value = Factorial <n> ::value /Factorial <k> ::value/ Factorial <n-k> ::value;
};

int main(int argc, char ** argv)
{
    std::cout << BinominalK<2, 2>::value << std::endl;


    return 0;
}
