//  Created by Дарья Землянская on 23.11.2020.
//  Copyright © 2020 Дарья Землянская. All rights reserved.
//

#include <iostream>

template<int n, int div>
struct is_prime_rec
{
  static const bool value = (n % div != 0) && is_prime_rec<n, div - 1>::value;
};

template<int n>
struct is_prime_rec<n, 1>
{
  static const bool value = true;
};

template<int n>
struct is_prime_rec<n, 0>
{
  static const bool value = true;
};

template<int n>
struct is_prime
{
  static const bool value = is_prime_rec<n, n - 1>::value;
};


template<int n>
struct next_prime;


template<int n, bool cond>
struct next_prime_if
{
  static const int value = n + 1;
};

template<int n>
struct next_prime_if<n, false>
{
  static const int value = next_prime<n + 1>::value;
};

template<int n>
struct next_prime
{
  static const int value = next_prime_if<n, is_prime<n + 1>::value>::value;
};

template<int i>
struct prime
{
  static const int value = next_prime<prime<i - 1>::value >::value;
};

template<>
struct prime<0>
{
  static const int value = 2;
};

int main()
{
    std::cout << prime<4>::value << std::endl; //11
    return 0;
}
