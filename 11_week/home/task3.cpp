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

template <typename U >
const bool is_array_t =  is_array <U>::value;

template <typename U >
const bool is_function_t =  is_function <U>::value;


template< typename T >
struct decay {
private:
    using U = typename std::remove_reference<T>::type; // удаляем ссылку
    using remove_extent = typename std::remove_extent<U>::type*;
    using add_pointer = typename std::add_pointer<U>::type;
public:
    //используем if_dev_else в зависимости что за тип T
    using type = if_then_else_t<
        is_array_t<U>,////Если T имя типа "массив элементов типа U" или "ссылка на массив элементов типа U",
        remove_extent, //// то определение типа будет U*
        if_then_else_t< //иначе - проверяем является ли это типом функции
            is_function_t<U>,
            add_pointer, //если да - возвращаем указатель
            remove_const<U> //в противном случая, удаляем константность
        >
    >;
};

//template<typename T, typename U>
//using dec_equiv = typename std::is_same<typename decay<T>::type, U>::type;

template<typename T, typename U>
inline const bool is_same_v = std::is_same<typename decay<T>::type, U>::value;

int main()
{
    std::cout << std::boolalpha // вкл булевские значения и проверяем
    
    << is_same_v<int, int> << '\n'
    << is_same_v<int&, int> << '\n'
    << is_same_v<int&&, int><< '\n'
    << is_same_v<const int&, int> << '\n'
    << is_same_v<int[2], int*> << '\n'
    << is_same_v<int(int), int(*)(int)> << '\n';
    return 0;
}


