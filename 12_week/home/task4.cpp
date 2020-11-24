//  Created by Дарья Землянская on 23.11.2020.
//  Copyright © 2020 Дарья Землянская. All rights reserved.
//

#include <iostream>
#include <array>

template<int size>
struct Simple{
    std::array<int, size> arr;
    constexpr Simple():arr(){
        int value = 1;
        for (int i = 0; i < size; i++)
        {
            bool prime = true;
            do{
                ++value;
                for (int j = 0; j < i && arr[j] <= value / 2 && (prime = value % arr[j] != 0); ++j){};
            } while (!prime);
     arr[i] = value;
        }
    }
    constexpr void print() const{
        std::cout << arr[size-1] << std::endl;
  }
};

int main() {
  constexpr Simple arr = Simple<6>();
  arr.print();
  return 0;
}
