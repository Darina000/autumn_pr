//  Created by Дарья Землянская on 28.10.2020.
//  Copyright © 2020 Дарья Землянская. All rights reserved.

#include <iostream>
#include <typeinfo>
#include <vector>

void underflow_error(){
    try
    {
       throw std::underflow_error( "The number's small" );
    }
    catch ( std::exception &e ) {
       std::cerr << "Caught: " << e.what( ) << " " << typeid( e ).name( ) << std::endl;
    };
}

class Base {virtual void member(){}};
class Derived : Base {};

void bad_cast(){
    try
    {
      Base b;
      Derived& rd = dynamic_cast<Derived&>(b);
    }
    catch (std::bad_cast& bc)
    {
       std::cerr << "bad_cast caught: " << bc.what() << std::endl;
    }
}


class Polymorphic {virtual void Member(){}};

void bad_typeid(){
    try
    {
      Polymorphic * pb = 0;
      std::cout << typeid(*pb).name();
    }
    catch (std::bad_typeid& bt)
    {
      std::cerr << "bad_typeid caught: " << bt.what() << std::endl;
    }
}

void lenght_error(){
    try {
      std::vector<int> myvector;
      myvector.resize(myvector.max_size()+1);
    }
    catch (const std::length_error& le) {
        std::cerr << "Length error: " << le.what() << std::endl;
    }
}
void out_of_range(){
    std::vector<int> myvector(10);
    try {
      myvector.at(20)=100;
    }
    catch (const std::out_of_range& oor) {
      std::cerr << "Out of Range error: " << oor.what() << std::endl;
    }
}



int main () {
    bad_typeid();
    lenght_error();
    out_of_range();
    bad_cast();
    underflow_error();
  return 0;
}
