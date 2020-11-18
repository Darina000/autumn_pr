//  Created by Дарья Землянская on 16.11.2020.
//  Copyright © 2020 Дарья Землянская. All rights reserved.
//
#include <iostream>
#include <type_traits>

// основа и специализации для обычной, вариативной, константной, ссылочной
template<typename>
struct is_function : std::false_type { };

template<typename Ret, typename... Args>
struct is_function<Ret(Args...)> : std::true_type {};
 
template<typename Ret, typename... Args>
struct is_function<Ret(Args...) const> : std::true_type {};

//для примера
struct A {
    int fun() const&;
};
auto func(){return 0;};

int main()
{
    std::cout << std::boolalpha;
    std::cout << is_function<A>::value << std::endl;
    std::cout << is_function<int(int)>::value << std::endl;
    std::cout << is_function<int>::value << std::endl;
    std::cout << is_function<int() const&>::value << std::endl;
    std::cout << is_function<decltype(func)>::value << std::endl; //decltype предписывает компилятору выбирать для них тип данных на основе типа инициализатора
    return 0;
}
