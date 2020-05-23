#ifndef ARRAY_H
#define ARRAY_H

#include <cassert>
#include <iostream>
template <class T>
class Array
{
private:
    int m_length{};
    T *m_data{};

public:

    Array(int length)
    {
        assert(length > 0);
        m_data = new T[length]{};
        m_length = length;
    }

    Array(const Array<T>& A){
        m_length = A.getLength();
        m_data = new T[m_length]{};
        for(int i{0};i<A.m_length;i++){
            m_data[i]=A.m_data[i];
        }
    }
    Array<T>& operator=(const Array<T>& A){
        m_length = A.m_length;
        delete[] m_data;
        m_data = new T[m_length]{};
        for(int i{0};i<A.m_length;i++){
            m_data[i]=A.m_data[i];
        }
        return *this;
    }

    ~Array()
    {
        delete[] m_data;
    }

    void Erase()
    {
        delete[] m_data;

        m_data = nullptr;
        m_length = 0;
    }

    T& operator[](int index)
    {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }
    template <typename C>
    friend Array<C> operator+(const Array<C>& A, const Array<C>& B);
    template <typename C>
    friend Array<C> operator-(const Array<C>& A, const Array<C>& B);
    template <typename C>
    friend Array<C> operator*(const Array<C>& A, const Array<C>& B);
    template <typename C>
    friend Array<C> operator*(const Array<C>& A, int x);
    int getLength() const;
};
template <class T>
int Array<T>::getLength() const // note class name is Array<T>, not Array
{
    return m_length;
}
template <typename C>
Array<C> operator+(const Array<C>& A, const Array<C>& B){
    Array<C> D(A.m_length);
    try{
        if(A.m_length!=B.m_length){
            throw "Khong the cong 2 mang do dai khac nhau!";
        }
    }
    catch(const char* exception){
        std::cerr<<"Error: "<<exception;
    }
    for(int i{0};i<A.m_length;i++){
        D.m_data[i]=A.m_data[i]+B.m_data[i];
    }
    return D;
}
template <typename C>
Array<C> operator-(const Array<C>& A, const Array<C>& B){
    Array<C> D(A.m_length);
    try{
        if(A.m_length!=B.m_length){
            throw "Khong the cong 2 mang do dai khac nhau!";
        }
    }
    catch(const char* exception){
        std::cerr<<"Error: "<<exception;
    }
    for(int i{0};i<A.m_length;i++){
        D.m_data[i]=A.m_data[i]-B.m_data[i];
    }
    return D;
}
template <typename C>
Array<C> operator*(const Array<C>& A, const Array<C>& B){
    Array<C> D(A.m_length);
    try{
        if(A.m_length!=B.m_length){
            throw "Khong the cong 2 mang do dai khac nhau!";
        }
    }
    catch(const char* exception){
        std::cerr<<"Error: "<<exception;
    }
    for(int i{0};i<A.m_length;i++){
        D.m_data[i]=A.m_data[i]*B.m_data[i];
    }
    return D;
}
template <typename C>
Array<C> operator*(const Array<C>& A, int x){
    Array<C> D(A.m_length);
    for(int i{0};i<A.m_length;i++){
        D.m_data[i]=A.m_data[i]*x;
    }
    return D;
}
#endif
