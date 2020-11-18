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

//удаление константности и псевдоним
template< typename T > struct remove_const{using type = T; };
template<typename T>
using remove_t = typename remove_const<T>::type;


//реализации из 1 задачи - основа и специализации для обычной, вариативной, константной
template<typename>
struct is_function : std::false_type { };

template<typename Ret, typename... Args>
struct is_function<Ret(Args...)> : std::true_type {};
 
template<typename Ret, typename... Args>
struct is_function<Ret(Args...) const> : std::true_type {};


template<typename T>
struct is_array : std::false_type {};
 
template<typename T>
struct is_array<T[]> : std::true_type {};
 
template<typename T, std::size_t N>
struct is_array<T[N]> : std::true_type {};



template< typename T >
struct decay {
private:
    using U = typename std::remove_reference<T>::type; // удаляем ссылку
    using remove_extent = typename std::remove_extent<U>::type*;
    using add_pointer = typename std::add_pointer<U>::type;
public:
    //используем if_dev_else в зависимости что за тип T
    using type = typename if_then_else<
        is_array<U>::value,////Если T имя типа "массив элементов типа U" или "ссылка на массив элементов типа U",
        remove_extent, //// то определение типа будет U*
        typename if_then_else< //иначе - проверяем является ли это типом функции
            is_function<U>::value,
            add_pointer, //если да - возвращаем указатель
            remove_const<U> //в противном случая, удаляем константность
        >::type
    >::type; // // и определяем тип как тип typedef члена
};

template<typename T, typename U>
using dec_equiv = typename std::is_same<typename decay<T>::type, U>::type;


int main()
{
    std::cout << std::boolalpha // вкл булевские значения и проверяем
    << dec_equiv<int, int>::value << '\n'
    << dec_equiv<int&, int>::value << '\n'
    << dec_equiv<int&&, int>::value<< '\n'
    << dec_equiv<const int&, int>::value << '\n'
    << dec_equiv<int[2], int*>::value << '\n'
    << dec_equiv<int(int), int(*)(int)>::value << '\n';
    return 0;
}

