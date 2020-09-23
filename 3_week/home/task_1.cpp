//  Created by Дарья Землянская on 21.09.2020.
//  Copyright © 2020 Дарья Землянская. All rights reserved.
//

#include <iostream>
#include <functional>

//1
void f1(unsigned int k){
   // double a = x;
    std::cout << "fun 1";
};
void f1(double x){
    std::cout << "fun 2";
};

//2
void f2(const int& k, double m){
    std::cout << "fun 1";
};
void f2(int y, double x){
    std::cout << "fun 2";
};

//3
void f3(int k = 3){
    std::cout << "fun 1";
};
void f3(double x = 6){
    std::cout << "fun 2";
};




int main() {
    
    //f1(1);
    //f2(3, 2);
    //f3();
    
    
    return 0;
}
