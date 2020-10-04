//  Created by Дарья Землянская on 04.10.2020.
//  Copyright © 2020 Дарья Землянская. All rights reserved.
//
#include <iostream>
#include <vector>
#include <cmath>
#include <string>

#include "City.hpp"

void City::change_name(const std::string &new_name){
    name = new_name;
    save_name(new_name);
};
    
void City::save_name(const std::string& name){
    old.push_back(name);
}


City::City(const std::string &a,const  std::vector <std::string> &s, const std::vector <double> &dist): name(a), street(s), distantion(dist)
{
    save_name(a);
}



