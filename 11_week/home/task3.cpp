//  Created by Дарья Землянская on 16.11.2020.
//  Copyright © 2020 Дарья Землянская. All rights reserved.
//

#include <iostream>
#include <type_traits>
//реализуем if_then_else как на семинаре - шаблон и специализация
template < bool C, typename True_Type, typename False_Type >
struct if_then_else
{
    using type = True_Type;
};

template < typename True_Type, typename False_Type >
struct if_then_else < false, True_Type, False_Type >
{
    using type = False_Type;
};

template < bool C, typename TT, typename FT >
using if_then_else_t = typename if_then_else < C, TT, FT >::type;


template< class T >
struct decay {
private:
    typedef typename std::remove_reference<T>::type U; // удаляем ссылку
public:
    //используем if_dev_else в зависимости что за тип T
    typedef typename if_then_else<
        std::is_array<U>::value, //если ссылка
        typename std::remove_extent<U>::type*, //удаляем её
        typename if_then_else< //иначе - проверяем является ли это типом функции
            std::is_function<U>::value,
            typename std::add_pointer<U>::type, //если да - возвращаем указатель
            typename std::remove_cv<U>::type //в противном случая, удаляем cv-qualifiers
        >::type
    >::type type; // // и определяем тип как тип typedef члена
};

//структура для проверки нашего преобразования
template <typename T, typename U>
struct decay_equiv :
    std::is_same<typename decay<T>::type, U>::type
{};

int main()
{
    std::cout << std::boolalpha // вкл булевские значения и проверяем
    << decay_equiv<int, int>::value << '\n'
    << decay_equiv<int&, int>::value << '\n'
    << decay_equiv<int&&, int>::value << '\n'
    << decay_equiv<const int&, int>::value << '\n'
    << decay_equiv<int[2], int*>::value << '\n'
    << decay_equiv<int(int), int(*)(int)>::value << '\n';
    return 0;
}
