//  Created by Дарья Землянская on 04.10.2020.
//  Copyright © 2020 Дарья Землянская. All rights reserved.
//

#include <iostream>
#include "energy.hpp"

int main() {
    double a;
    std::cout << "Enter the energy value in Joules: ";
    std::cin >> a;
    Energy one(a);
    one.Print_all();
    
    
    return 0;
}
