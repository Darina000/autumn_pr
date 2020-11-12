//  Created by Дарья Землянская on 11.11.2020.
//  Copyright © 2020 Дарья Землянская. All rights reserved.
//

#include <iostream>
#include <vector>

template<typename Derived>
class Base{
public:
    void print()
    {
        self()->Print();
    }
private:
    Derived* self()
    {
        return static_cast<Derived*>(this);
    }
    
};

class Derived: public Base<Derived>
{
    friend class Base<Derived>;
private:
    void Print()
    {
        std::cout << "Print m " << m_Counter << "\n";
    }
private:
    int m_Counter = 0;
};

int main()
{
   
    return 0;
}
