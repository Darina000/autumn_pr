//  Created by Дарья Землянская on 26.09.2020.
//  Copyright © 2020 Дарья Землянская. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <string>

struct City{
    City():name("Noname"), street({"None"}), distantion({0}) {
    }
    
    ~City(){
    }
    
    City(std::string a, std::vector <std::string> s, std::vector <double> dist): name(a), street(s), distantion(dist)
    {
        save_name(a);
    }

    std::string name;
    std::vector <std::string> street;
    std::vector <double> distantion;
    std::vector <std::string> old;
    
    void change_name(std::string new_name){
        name = new_name;
        save_name(new_name);
    }
    
    void save_name(std::string name){
        old.push_back(name);
    }
    const double PI = 3.14159265;
    double Gaversinus(const std::vector <double>& d1 ,const std::vector <double>& d2) {
        double R = 6371; // радиус Земли в км.
        double lat = (d2[0]-d1[0])*(PI/180);
        double lon = (d2[1]-d1[1])*(PI/180);
        double rez = sin(lat/2)*sin(lat/2)+cos(d1[0]*(PI/180))*cos(d2[0]*(PI/180))*sin(lon/2)*sin(lon/2);
        double d = 2*R*atan2(sqrt(rez), sqrt(1-rez));
        return d;
    }
    
    void dist(const struct City& a){
        std::cout << Gaversinus(distantion, a.distantion) <<  std::endl;
    }
    
};

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
    City Peter = {"St. Petersburg", v1, d1};
    
    Peter.change_name("Petrograd");
    Peter.change_name("Leningrad");
    Print_v(Peter.old);
    
    std::vector <std::string> v2 = {"Babaeva", "Arbat", "Tverskaya"};
    std::vector <double> d2 = {55.7, 37.6};
    City Moscow = {"Moscow", v2, d2};
    
    Moscow.dist(Peter);

    return 0;
}
