
//  Created by Дарья Землянская on 04.10.2020.
//  Copyright © 2020 Дарья Землянская. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <string>

#include "City.hpp"

void Print_v(const std::vector <std::string>& v){
    for (auto i: v){
        std::cout << i << " ";
    }
    std::cout << std::endl;
}
void Print_v(const std::vector <double>& v){
    for (auto i: v){
        std::cout << i << " ";
    }
    std::cout << std::endl;
}



int main() {
    
    std::vector <std::string> v1 = {"Nevskiy", "Ligovskiy", "Sadovaya"};
    std::vector <double> d1 = {59.9, 30.34};
    
    City Peter("St. Petersburg", v1, d1);
    City* Pt = &Peter;
    
    Pt -> change_name("Petrograd");
    Pt -> change_name("Leningrad");
    Print_v(Pt -> City::return_old());
    
    std::vector <std::string> v2 = {"Babaeva", "Arbat", "Tverskaya"};
    std::vector <double> d2 = {55.7, 37.6};
    City Moscow("Moscow", v2, d2);
    City * Msc = &Moscow;
    
    dist(*Pt, *Msc);

    return 0;
}
