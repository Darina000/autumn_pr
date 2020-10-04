
//  Created by Дарья Землянская on 04.10.2020.
//  Copyright © 2020 Дарья Землянская. All rights reserved.
//
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <stdio.h>

#include "City.hpp"

void dist( City& a,  City& b ){
    std::vector <double> d1 = a.return_dist();
    std::vector <double> d2 = b.return_dist();
    const double PI = 3.14159265;
    double R = 6371.0;
    double lat = (d2[0]-d1[0])*(PI/180);
    double lon = (d2[1]-d1[1])*(PI/180);
    double rez = sin(lat/2)*sin(lat/2)+cos(d1[0]*(PI/180))*cos(d2[0]*(PI/180))*sin(lon/2)*sin(lon/2);
    double d = 2*R*atan2(sqrt(rez), sqrt(1-rez));
    std::cout << d <<  std::endl;
}
