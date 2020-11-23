//  Created by Дарья Землянская on 23.11.2020.
//  Copyright © 2020 Дарья Землянская. All rights reserved.
//

#include <iostream>

constexpr double exp(double eps)
{
    double sum = 1.0;
    double s = 1.0;

    for(double n = 1.0; s > eps; ++n)
    {
        sum += (s *= 1/n);
    }

    return sum;
}

int main()
{
    constexpr double result = exp(0.01);
    std::cout << result << std::endl;
    return 0;
}

