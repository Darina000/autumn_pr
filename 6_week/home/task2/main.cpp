//  Created by Дарья Землянская on 14.10.2020.
//  Copyright © 2020 Дарья Землянская. All rights reserved.
//

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>

#include "f.hpp"


int main() {
    Fraction first;
    Fraction sec;
    //Frac first(3, 5);
    //Frac sec(6, 4);
    
    std::cin >> first;
    std::cin >> sec;
    
    std::cout << first << std::endl;
    std::cout << sec << std::endl;
    
    first/sec;
    first + sec;
    first - sec;
    std::cout << (first > sec) << std::endl; 
    first*=sec;
    sec/=first;
    
    
    
    
    return 0;
}
