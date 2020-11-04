//  Created by Дарья Землянская on 02.11.2020.
//  Copyright © 2020 Дарья Землянская. All rights reserved.
//

#include <iostream>
#include <typeinfo>
#include <vector>

class MyException: public std::exception{
public:
    MyException(std::string error)
        : m_error(error)
    {
    }
    const char* what() const noexcept override { return m_error.c_str(); }
private:
    std::string m_error;
};


template <typename T>
class X{
public:
    
    X();
    X(T c);
    X(const T * c);
    X(const X & other);
    X(X && other);
    
    X(std::size_t length);
    
    ~X();
    
    void resize(std::size_t newLenght);
    void erase();
    void swap(X & other);
    std::size_t length() const;
    
    T   operator[] (std::size_t index) const;
    T & operator[] (std::size_t index);
    
    X & operator= (const X & other);
    X & operator= (X && other);

private:
    T *       m_data;
    std::size_t  m_length;
    
};

template <typename T>
X<T>::X(): m_data(nullptr), m_length(0)
{
}

template <typename T>
X<T>::X(std::size_t length):m_length(length)
    {
        assert(length >= 0);
        if (length > 0){
            m_data = new T[length];
        }
        else{
            m_data = nullptr;
       }
    }



template <typename T>
X<T>::X(T c): m_length(1)
{
    m_data = new T[1];
    *m_data = c;
}

template <typename T>
X<T>::X(const T * c_)
{
    if(c_)
    {
        m_length = strlen(c_);
        m_data = new T[m_length];
        for(std::size_t i = 0; i < m_length; ++i)
            m_data[i] = c_[i];
    }else{
        m_length = 0;
        m_data = nullptr;
    }
}
//копирующий конструктор
template <typename T>
X<T>::X(const X & other):
m_length(other.m_length)
{
    m_data = new T[m_length];
    for(std::size_t i = 0U; i < m_length; ++i){
       m_data[i] = other.m_data[i];
    }
}
//перемещающий конструктор
template <typename T>
X<T>::X(X && other):
m_length(other.m_length),
m_data(other.m_data)
{
    other.m_data = nullptr;
    other.m_length = 0;
}


template <typename T>
X<T>::~X()
{
    if(m_data != nullptr)
    delete[] m_data;
}

template <typename T>
void X<T>::erase()
   {
       delete[] m_data;
       m_data = nullptr;
       m_length = 0;
   }

template <typename T>
void X<T>::resize(std::size_t newLength)
   {
       if (newLength == m_length)
          // throw (MyException("newLength == m_length"));
           return;
       
       if (newLength <= 0)
       {
           erase();
           return;
       }

       T *data = new T[newLength];
       if (m_length > 0)
       {
           int elementsToCopy = (newLength > m_length) ? m_length : newLength;
           for (int index=0; index < elementsToCopy ; ++index)
               data[index] = m_data[index];
       }
       delete[] m_data;
       m_data = data;
       m_length = newLength;
   }

template <typename T>
void X<T>::swap(X & other)
{
    std::swap(m_data, other.m_data);
    std::swap(m_length, other.m_length);
}

template <typename T>
std::size_t X<T>::length() const
{
    return m_length;
}

template <typename T>
T X<T>::operator[] (std::size_t index) const
{
    if (index >= m_length) { throw (MyException("index >= m_length")); };
    return m_data[index];
}

template <typename T>
T & X<T>::operator[] (std::size_t index)
{
    if (index >= m_length) { throw (MyException("index >= m_length")); };
    return m_data[index];
}

template <typename T>
X<T> & X<T>::operator= (const X & other)
{
    if (this == &other) return *this;

    if(m_data != nullptr)
        delete[] m_data;

    m_length = other.m_length;
    m_data = new T[m_length];
    for (std::size_t i = 0; i < m_length; ++i)
        m_data[i] = other.m_data[i];

    return *this;
}

template <typename T>
X<T> & X<T>::operator= (X && other)
{
    if (this == &other) return *this;

    if (m_data != nullptr)
        delete[] m_data;

    swap(other);
    other.m_length = 0;
    other.m_data = nullptr;

    return *this;
}


int main()
{
    try{
    std::size_t a = 10;
    X<int> array(a);
    
    for (int i=0; i<10; i++){
           array[i] = i+1;
    }
    array.resize(7);
    
    for (int i = 0; i<array.length(); ++i){
        std::cout << array[i] << " ";
    }
    }
    catch(const MyException &c){
        std::cerr << c.what();
    }
    catch(const std::exception &c){
        std::cerr << "Other std::exception occurred: " << c.what() << std::endl;
    }
    catch(...){
        std::cerr << "ERROR " << std::endl;
    }
    return 0;
}
