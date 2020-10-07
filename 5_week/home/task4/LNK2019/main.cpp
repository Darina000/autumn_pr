//  Created by Дарья Землянская on 05.10.2020.
//  Copyright © 2020 Дарья Землянская. All rights reserved.
//

#include <iostream>
#include "f.hpp"

/*
 Ошибка линковщика LNK2019 с неразрешенным внешним символом.
 В этом примере переменная extern int x;  объявлена в hpp файле, но не определена(определение закоментино в файле f.cpp)
 */
int main() {
    std::cout << "It's main" << std::endl;
    std::cout << x << std::endl;
    return 0;
}
