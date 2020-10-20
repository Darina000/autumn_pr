//  Created by Дарья Землянская on 12.10.2020.
//  Copyright © 2020 Дарья Землянская. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstdint>
#include <utility>

class Cass{
private:
    int *       m_data;
    std::size_t  m_length;
    std::vector<int>  m_vector;
    
public:
    Cass();
    Cass(int c);
    Cass(const int * c_n);
    Cass(const Cass & other);
    Cass(std::vector<int> vect);
    Cass(Cass && other);
    ~Cass();
    
    void swap(Cass & other);
    
    
    Cass & operator= (const Cass & other);
    Cass & operator= (Cass && other);
    
    friend std::ostream& operator<< (std::ostream &out, const Cass &cass);
};

std::ostream& operator<< (std::ostream &out, const Cass &cass)
{
    out << "lenght " << cass.m_length << " data " ;
    if (cass.m_data != nullptr){
        for (auto i = 0; i < cass.m_length; ++i){
            out << cass.m_data[i] << " ";
        }
    }
    out << "vector ";
    for (auto i: cass.m_vector){
        std::cout << i;
    }
    out << std::endl;
    return out;
}

//конструктор по умолчанию
Cass::Cass() : m_length(0), m_data(nullptr), m_vector{0}
{
    
}
//пользовательский конструктор для символа
Cass::Cass(int c) : m_length(1)
{
    m_data = new int[1];
    m_data[0] = c;
    m_vector.push_back(1);
}

// пользовательский конструктор дл€ —- вектора
Cass::Cass(std::vector<int> vect): m_length(1), m_data(nullptr)
{
    m_vector = vect;
    
}

//копирующий конструктор
Cass::Cass(const Cass & other) :
    m_length(other.m_length), m_vector(other.m_vector)
{
    m_data = new int[m_length];
    for (std::size_t i = 0U; i < m_length; ++i){
        m_data[i] = other.m_data[i];
    }
}
//перемещающий конструктор
Cass::Cass(Cass && other) :
m_length(other.m_length), m_data(other.m_data), m_vector(std::move(other.m_vector))
{
    other.m_length = 0;
    other.m_data = nullptr;
    m_vector.clear();
    
}
//деструктор
Cass::~Cass()
{
    if(m_data != nullptr)
        delete[] m_data;
}


void Cass::swap(Cass & other)
{
    std::swap(this->m_length, other.m_length);
    std::swap(this->m_data, other.m_data);
    std::swap(this->m_vector, other.m_vector);
}


//копирующий оператор=

Cass & Cass::operator= (const Cass & other)
{
    if (this == &other) return *this;

    if(m_data != nullptr)
        delete[] m_data;

    m_length = other.m_length;
    m_vector = other.m_vector;
    m_data = new int[m_length];
    if (other.m_data != nullptr){
        for (auto i = 0; i < m_length; ++i){
            m_data[i] = other.m_data[i];
        }
    }
    return *this;
}

//перемещающий оператор=
Cass & Cass::operator= (Cass && other)
{
    if (this == &other) return *this;
    
    if (m_data != nullptr)
        delete[] m_data;

    swap(other);
    other.m_length = 0;
    other.m_data = nullptr;
    other.m_vector.clear();
    

    return *this;
}





int main() {
    int a = 5;
    int b = 10;
    int n = 5;
    int* arr = new int [n]{3, 6, 1, 7, 3};
    std::vector<int> v1 = {0, 7, 3};
    std::vector<int> v2 = {5, 2, 9};
    Cass one(a);
    Cass two;
    
    Cass vec1(v1);
    Cass vec2(v2);
    Cass vec(3);
    Cass v = 4;
    
    std::cout << vec1;
    std::cout << vec2;
    vec2 = vec1;
    std::cout << vec1;
    std::cout << vec2;
    vec2 =vec;
    std::cout << vec2;
    std::cout << v;
    vec = Cass(12);
    std::cout << vec;
    return 0;
}

