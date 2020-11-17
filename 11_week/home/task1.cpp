//  Created by Дарья Землянская on 16.11.2020.
//  Copyright © 2020 Дарья Землянская. All rights reserved.
//
#include <iostream>
#include <type_traits>

//псевдонимы
using t = std::true_type;
using f = std::false_type;
// основа и специализации для обычной, вариативной, константной, ссылочной
template<class>
struct is_function : f { };

template<class Ret, class... Args>
struct is_function<Ret(Args...)> : t {};
 
template<class Ret, class... Args>
struct is_function<Ret(Args...) const> : t {};

// specialization for function types that have ref-qualifiers
template<class Ret, class... Args>
struct is_function<Ret(Args...) &> : t {};

template<class Ret, class... Args>
struct is_function<Ret(Args...) const &> : t {};


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
