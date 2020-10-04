//  Created by Дарья Землянская on 04.10.2020.
//  Copyright © 2020 Дарья Землянская. All rights reserved.
//

#ifndef City_hpp
#define City_hpp

#include <stdio.h>

class City{
private:
    std::string name;
    std::vector <std::string> street;
    std::vector <double> distantion;
    std::vector <std::string> old;
    
public:
    City():name{"Noname"}, street{"None"}, distantion{0}{}
    ~City(){}
    City(const std::string &a,const  std::vector <std::string> &s, const std::vector <double> &dist);
    
    void change_name(const std::string &new_name);
    void save_name(const std::string& name);
    
    std::vector <double> return_dist(){ return distantion;};
    std::vector <std::string> return_old(){return old;};
    
    friend void dist( City& a,  City& b );
    
};


#endif /* City_hpp */
