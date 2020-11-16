//  Created by Дарья Землянская on 11.11.2020.
//  Copyright © 2020 Дарья Землянская. All rights reserved.
//

#include <iostream>


class VirtualBase
{
public:
    virtual void print() const = 0;
    virtual ~VirtualBase() = default;
};



class VirtualImpl: public VirtualBase
{
public:
    virtual void print() const override{
        std::cout << "Virtual Impl counter: " << m_Counter << "\n";
    }
    ~VirtualImpl() = default;
private:
    int m_Counter = 0;
};




template<typename Derived>
class Base{
public:
    virtual ~Base() = default;
    
    void print()
    {
        self()->Print();
    }
protected:
    Derived* self()
    {
        return static_cast<Derived*>(this);
    }
    
};

class Derived: public Base<Derived>
{
public:
    friend class Base<Derived>;
    virtual ~Derived() = default;
    
    void Print()
    {
        std::cout << "Print m " << m_Counter << "\n";
    }
private:
    int m_Counter = 0;
};

int main()
{
    Derived a;
    VirtualImpl b;
    a.print();
    b.print();
   
    return 0;
}

