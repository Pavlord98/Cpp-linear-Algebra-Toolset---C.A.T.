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
    
    bVector(std::string type = "column");
    bVector(std::vector<T> inputData, std::string type = "column");
    ~bVector();

    //***********Describing**************** 
    
    std::string getType();

    int length();

    
    //******Element access*************

    T getElement(int index);

    // overlaad () and add advanced slicing and indexing

    // maybe concat()

    //*********Vector operations*************

    bVector<T> operator+ (const bVector<T> &b) const;
    bVector<T> operator- (const bVector<T> &b) const;
    bVector<T> operator* (const bVector<T> &b) const;

    template <class U> friend bVector<U> operator* (const U &scalar, const bVector<U> &vector);

    static T dot(const bVector<T> &a, const bVector<T> &b);
    static bVector<T> cross(const bVector<T> &a, const bVector<T> &b);

 private:
    std::vector<T> m_vectorData;
    int m_length;
    std::string m_type;
};

#include "constructors.inl"
#include "describing.inl"







#endif