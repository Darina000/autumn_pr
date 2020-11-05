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
    
    using size_type  = std::size_t;
    using reference  = X&;
    using const_reference  = const X&;
    
    X();
    X(T c, size_type lenght);
    X(const T * c, size_type a);
    X(const T * c, size_type a, T b);
    X(const_reference other);
    X(X && other);
    
    X(size_type length);
    
    ~X() noexcept{
    };
    
    void resize(size_type newLenght);
    void clear();
    void swap(reference other) noexcept;
    std::size_t length() const noexcept;
    
    T   operator[] (size_type index) const;
    T & operator[] (size_type index);
    
    reference operator= (const_reference other);
    reference operator= (X && other);
    
private:
    T *       m_data;
    size_type  m_length;
};

template <typename T>
X<T>::X(): m_data(nullptr), m_length(0)
{
}

template <typename T>
X<T>::X(size_type length):m_length(length)
    {
        if (length > 0){
            m_data = new T[length];
            for (std::size_t i = 0; i< length; ++i){
                m_data[i] = 0;
            }
        }
        else{
            m_data = nullptr;
       }
    }



template <typename T>
X<T>::X(T c, size_type a): m_length(a)
{
    m_data = new T[m_length];
    *m_data = c;
}

template <typename T>
X<T>::X(const T * c_, size_type a): m_length(a)
{
    if(c_)
    {
        m_data = new T[m_length];
        for(size_type i = 0; i < m_length; ++i)
            m_data[i] = c_[i];
    }else{
        m_length = 0;
        m_data = nullptr;
    }
}


template <typename T>
X<T>::X(const T * c_, size_type a, T b): m_length(a)
{
    if(c_)
    {
        m_data = new T[m_length];
        for(size_type i = 0; i < m_length; ++i)
            m_data[i] = c_[b];
    }else{
        m_length = 0;
        m_data = nullptr;
    }
}
//копирующий конструктор
template <typename T>
X<T>::X(const_reference other):
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
void X<T>::clear()
   {
       delete[] m_data;
       m_data = nullptr;
       m_length = 0;
   }

template <typename T>
void X<T>::resize(size_type newLength)
   {
       if (newLength == m_length)
           return;

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
void X<T>::swap(reference other) noexcept
{
    std::swap(m_data, other.m_data);
    std::swap(m_length, other.m_length);
}

template <typename T>
std::size_t X<T>::length() const noexcept
{
    return m_length;
}

template <typename T>
T X<T>::operator[] (size_type index) const
{
    return m_data[index];
}

template <typename T>
T & X<T>::operator[] (size_type index)
{
    return m_data[index];
}

template <typename T>
X<T> & X<T>::operator= (const_reference other)
{
    if (this == &other) return *this;

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
        
    X<int> ar(4);
        
    for (int i = 0; i<ar.length(); ++i){
        std::cout << ar[i] << " ";
    }
        std::cout << std::endl;
        
    
    for (int i=0; i<10; i++){
           array[i] = i+1;
    }
    array.resize(7);
    
    for (int i = 0; i<array.length(); ++i){
        std::cout << array[i] << " ";
    }
        std::cout << std::endl;
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
