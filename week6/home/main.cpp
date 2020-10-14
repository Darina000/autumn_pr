//  Created by Дарья Землянская on 12.10.2020.
//  Copyright © 2020 Дарья Землянская. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstdint>
#include <utility>
class Cass{
private:
    char *       m_data;
    std::size_t  m_length;
    std::vector<int>  m_vector;
    
public:
    Cass();
    Cass(char c);
    Cass(const char * c_n);
    Cass(const Cass & other);
    Cass(const int vect);
    Cass(Cass && other);
    ~Cass();
    
    void swap(Cass & other);
    
    void Prt_data();
    void Prt_lenght();
    void Prt_vector();
    
    Cass & operator= (const Cass & other);
    Cass & operator= (Cass && other);
};

//конструктор по умолчанию
Cass::Cass() : m_length(0), m_data(nullptr), m_vector{}
{}

//пользовательский конструктор для символа
Cass::Cass(char c) : m_length(1)
{
    m_data = new char[1];
    m_data[0] = c;
    m_vector[0] = c;
}
// пользовательский конструктор дл€ —-строки
Cass::Cass(const char * c_n)
{
    if (c_n)
    {
        m_length = strlen(c_n);
        m_data = new char[m_length];
        for (std::size_t i = 0U; i < m_length; ++i){
            m_data[i] = c_n[i];
        }
        for (std::size_t i = 0U; i < m_length; ++i){
            m_vector[i] = c_n[i];
        }
    }
    else
    {
        m_length = 0;
        m_data = nullptr;
        m_vector = {};
    }
}
// пользовательский конструктор дл€ —- вектора
Cass::Cass(const int vect): m_length(1), m_data(nullptr)
{
    m_vector[0] = vect;
}
//копирующий конструктор
Cass::Cass(const Cass & other) :
    m_length(other.m_length)
{
    m_data = new char[m_length];
    for (std::size_t i = 0U; i < m_length; ++i){
        m_data[i] = other.m_data[i];
    }
    for (std::size_t i = 0U; i < m_length; ++i){
        m_vector[i] = other.m_vector[i];
    }
}
//перемещающий конструктор
Cass::Cass(Cass && other) :
m_length(other.m_length), m_data(other.m_data), m_vector(std::move(other.m_vector))
{
    other.m_length = 0;
    other.m_data = nullptr;
    other.m_vector = {};
    
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
    m_data = new char[m_length];
    for (std::size_t i = 0; i < m_length; ++i)
        m_data[i] = other.m_data[i];

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
    other.m_vector = std::move(m_vector);

    return *this;
}





int main() {
    Cass a(5);
    return 0;
}
