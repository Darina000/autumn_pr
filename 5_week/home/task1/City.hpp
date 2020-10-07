//  Created by Дарья Землянская on 04.10.2020.
//  Copyright © 2020 Дарья Землянская. All rights reserved.
//

#ifndef City_hpp
#define City_hpp
#include <vector>
#include <iostream>
#include <string>

class City{
public:
    City():name{"Noname"}, street{"None"}, distantion{0}{}
    ~City(){}
    City(const std::string &a,const  std::vector <std::string> &s, const std::vector <double> &dist);
    
    const auto& return_dist()const { return distantion;};
    const auto& return_old()const {return old;};
    
    
    void change_name(const std::string &new_name);
    void save_name(const std::string& name);
    
    friend std::ostream& operator<< (std::ostream &os, const City &city);
    
private:
    std::string name;
    std::vector <std::string> street;
    std::vector <double> distantion;
    std::vector <std::string> old;
    
};
