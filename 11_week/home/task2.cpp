//  Created by Дарья Землянская on 16.11.2020.
//  Copyright © 2020 Дарья Землянская. All rights reserved.
//

#include <iostream>
#include <type_traits>

//делаем для разных типов очистку от константности
template< typename T > struct remove_const{using type = T; };
template< typename T > struct remove_const<const T>{ using type = T; };
//добавляем константность для любого принятного типа (очищая от остального)
template< typename T > struct add_const{ using type = const T; };

template<typename T>
using remove_t = typename remove_const<T>::type;

template<typename T>
using add_t = typename add_const<T>::type;


int main() {
    std::cout << std::boolalpha; //вкл отображение булевских значений в слова
    std::cout << std::is_const <add_t<const int>>::value << std::endl; // добавим и проверим константность
    std::cout << std::is_const <remove_t<const int>>::value << std::endl; // удалим константность b проверим отсутствие константности
    
  return 0;
}
