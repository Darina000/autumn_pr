//  Created by Дарья Землянская on 08.11.2020.
//  Copyright © 2020 Дарья Землянская. All rights reserved.
//

#include <iostream>



template<typename F, typename ... T>
auto Func(F function, T ... arr)
{
    return function(arr...);
}

int main()
{
    Func([](int x, int y){return x>y;}, 4, 0);
}
