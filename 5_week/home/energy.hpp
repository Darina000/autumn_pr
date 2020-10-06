//  Created by Дарья Землянская on 04.10.2020.
//  Copyright © 2020 Дарья Землянская. All rights reserved.
//

#ifndef energy_hpp
#define energy_hpp

#include <stdio.h>
#include <iostream>

class Energy{
public:
    Energy():en_Joule(1){}
    
    ~Energy(){}
    
    Energy(double en_J): en_Joule(en_J){};
    
    double return_inErg();
    double return_inIntCalory();
    double return_inElVolt();
    
    void Print_all();
    
    static const double a_ElVolt;
    static const double a_IntCalory;
    static const double a_Erg;
    
private:
    double en_Joule;
};


#endif
