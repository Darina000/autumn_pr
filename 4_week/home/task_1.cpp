//  Created by Дарья Землянская on 26.09.2020.
//  Copyright © 2020 Дарья Землянская. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <string>


struct City{
    City():name{"Noname"}, street{"None"}, distantion{0}{
    }
    
    ~City(){
    }
    
    City(const std::string &a,const  std::vector <std::string> &s, const std::vector <double> &dist): name(a), street(s), distantion(dist)
    {
        save_name(a);
    }
    
    void change_name(const std::string &new_name){
        name = new_name;
        save_name(new_name);
    }
    
    void save_name(const std::string& name){
        old.push_back(name);
    }
    
    std::string name;
    std::vector <std::string> street;
    std::vector <double> distantion;
    std::vector <std::string> old;
    
};

void dist(const struct City& a, const struct City& b ){
    std::vector <double> d1 = a.distantion;
    std::vector <double> d2 = b.distantion;
    const double PI = 3.14159265;
    double R = 6371.0;
    double lat = (d2[0]-d1[0])*(PI/180);
    double lon = (d2[1]-d1[1])*(PI/180);
    double rez = sin(lat/2)*sin(lat/2)+cos(d1[0]*(PI/180))*cos(d2[0]*(PI/180))*sin(lon/2)*sin(lon/2);
    double d = 2*R*atan2(sqrt(rez), sqrt(1-rez));
    std::cout << d <<  std::endl;
}

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
    Print_v(Pt -> old);
    
    std::vector <std::string> v2 = {"Babaeva", "Arbat", "Tverskaya"};
    std::vector <double> d2 = {55.7, 37.6};
    City Moscow("Moscow", v2, d2);
    City * Msc = &Moscow;
    
    dist(*Pt, *Msc);

    return 0;
}

