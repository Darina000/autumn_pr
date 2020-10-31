//  Created by Дарья Землянская on 28.10.2020.
//  Copyright © 2020 Дарья Землянская. All rights reserved.
//

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>

#include "f.hpp"


int main() {
    //Frac first(3, 5);
    //Frac sec(6, 4);
    try{
        Fraction first;
        Fraction sec;
        std::cin >> first;
        std::cin >> sec;
        
        std::cout << first << std::endl;
        std::cout << sec << std::endl;
        std::cout << first/sec << std::endl;
    }
    catch(const MyException &c){
        std::cerr << c.what();
    }
    catch(const std::exception &c){
        std::cerr << "Other std::exception occurred: " << c.what() << std::endl;
    }
    catch(...){
        std::cerr << "ERROR " << std::endl;
    }
    
    
    
    
    return 0;
}
