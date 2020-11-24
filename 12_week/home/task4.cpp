//  Created by Дарья Землянская on 23.11.2020.
//  Copyright © 2020 Дарья Землянская. All rights reserved.
//

#include <array>
#include <iostream>

template < int size >
constexpr int Simple()
{
    std::array<int, size> arr{};
    int value = 1;
    for (int i = 0; i < size; i++)
       {
           bool prime = true;
           do{
               ++value;
               for (int j = 0; j < i && arr[j] <= value / 2 && (prime = value % arr[j] != 0); ++j){};
           } while (!prime);
           arr[i] = value;
       }
    return arr[size-1];
}

int main()
{
    constexpr double result = Simple<4>();
    std::cout << result << std::endl;
    return 0;
}
