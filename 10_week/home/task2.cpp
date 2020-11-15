//  Created by Дарья Землянская on 08.11.2020.
//  Copyright © 2020 Дарья Землянская. All rights reserved.
//

#include <iostream>

template<typename T, typename ... TT>
auto make(TT ... args)
{
    return new T(args...);
}


int main() {
    auto ptr = make<int> (5);
    delete ptr;
    return 0;
}
