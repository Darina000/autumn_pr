//  Created by Дарья Землянская on 16.11.2020.
//  Copyright © 2020 Дарья Землянская. All rights reserved.
//

#include <iostream>
#include <type_traits>

//делаем для разных типов очистку от константности
template< typename T > struct remove_const{using type = T; };
template< typename T > struct remove_const<const T>{ using type = T; };
template< typename T > struct remove_const<const T&>{ using type = T; };
template< typename T > struct remove_const<const T&&>{ using type = T; };
//добавляем константность для любого принятного типа (очищая от остального)
template< typename T > struct add_const{ using type = const T; };

int main() {
    std::cout << std::boolalpha; //вкл отображение булевских значений в слова
    typedef add_const<int>::type A; // добавим константность инту
    std::cout << std::is_const<A>::value << std::endl; //проверим константность
    typedef remove_const<A>::type B; //удалим константность и назовём тип
    std::cout << std::is_const<B>::value << std::endl; // проверим отсутствие константности
    
  return 0;
}
