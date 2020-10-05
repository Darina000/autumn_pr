//  Created by Дарья Землянская on 05.10.2020.
//  Copyright © 2020 Дарья Землянская. All rights reserved.
//

#include <iostream>
#include "f.hpp"

/*
 Ошибка линковщика LNK2019 с неразрешенным внешним символом.
 В этом примере переменная extern void f();  объявлена в hpp файле, но не определена(функция которая должна быть я закоментила в соответствующем файле f.cpp)
 */
int main() {
    std::cout << "It's main" << std::endl;
    f();
    return 0;
}
