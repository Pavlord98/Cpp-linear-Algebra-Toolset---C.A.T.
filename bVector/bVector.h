#ifndef BVECTOR_H
#define BVECTOR_H

#include <stdexcept>
#include <iostream>
#include <math.h>
#include <vector>
#include <string>

template <class T>
class bVector
{
 public:
    //******Constructors*************
    
    bVector();
    bVector(std::vector<T> inputData);
    ~bVector();

    //***********Describing**************** 
    
    std::string getType();

    int length();

    void print();

    
    //******Element access*************

    T getElement(int index) const;

    void setElement(int index, T value);

    // overlaad () and add advanced slicing and indexing

    // maybe concat()

    //*********Vector operations*************

    bVector<T> operator+ (const bVector<T> &b) const;
    bVector<T> operator- (const bVector<T> &b) const;
    bVector<T> operator* (const T &scalar) const;

    template <class U> friend bVector<U> operator* (const U &scalar, const bVector<U> &vector);

    T norm();
    bVector<T> normalized();
    void normalize();

    static T dot(bVector<T> &a, bVector<T> &b);
    static bVector<T> cross(const bVector<T> &a, const bVector<T> &b);

 private:
    std::vector<T> m_vectorData;
    int m_length;
    //std::string m_type;
};

#include "constructors.inl"
#include "describing.inl"
#include "elementAccess.inl"
#include "vectorOperations.inl"







#endif