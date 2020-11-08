//  Created by Дарья Землянская on 08.11.2020.
//  Copyright © 2020 Дарья Землянская. All rights reserved.
//

#include <iostream>


auto Sum2()
{
  return 0;
}

template<typename Arg, typename... Args>
auto Sum2(Arg first, Args... Values)
{
    Arg* A = new Arg;
    Sum2(Values...);
    
    return *A;
}


int main() {
    std::cout << Sum2<int>(3, 4) << std::endl;
    return 0;
}
