//  Created by Дарья Землянская on 08.11.2020.
//  Copyright © 2020 Дарья Землянская. All rights reserved.
//

#include <iostream>


template<typename... T>
auto Sum1(T... Values)
{
  return (sizeof(Values) + ...);
}

auto Sum2()
{
  return 0;
}

template<typename Arg, typename... Args>
auto Sum2(Arg first, Args... Values)
{
  return sizeof(first) + Sum2(Values...);
}


int main() {
    std::cout << Sum1('a', 1, 'wd') << std::endl;
    std::cout << Sum2('a', 1, 'wd') << std::endl;
    return 0;
}
