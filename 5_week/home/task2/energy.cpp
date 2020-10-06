//  Created by Дарья Землянская on 04.10.2020.
//  Copyright © 2020 Дарья Землянская. All rights reserved.
//

#include "energy.hpp"
#include <cmath>

const double Energy::a_ElVolt = 0.624146*pow(10,19);
const double Energy::a_IntCalory = 0.238846;
const double Energy::a_Erg = 10000000.0;


double Energy::return_inErg(){
    return en_Joule*a_Erg;
};
double Energy::return_inIntCalory(){
    return en_Joule*a_IntCalory;
};

double Energy::return_inElVolt(){
    return en_Joule*a_ElVolt;
};

void Energy::Print_all(){
    std::cout << "In Erg: " << return_inErg() << std::endl;
    std::cout << "In Volt: " << return_inElVolt() << std::endl;
    std::cout << "In Calory: " << return_inIntCalory() << std::endl;
}

