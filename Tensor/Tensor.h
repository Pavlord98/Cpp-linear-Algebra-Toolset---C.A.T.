#ifndef TENSOR_H
#define TENSOR_H

#include <string>
#include <typeinfo>
#include <iostream>

#include <stdexcept>
#include <math.h>
#include <vector>

template <class T>
class Tensor
{
 public:
    //******Constructors*************
    Tensor();
    
    ~Tensor();


    //******Matrix operations*************
    // operator =
    //template <class U> friend bMatrix<U> operator= (const bMatrix<U>& A, const bMatrix<U>& B);

    // operator +
    template <class U> friend Tensor<U> operator+ (const Tensor<U>& A, const Tensor<U>& B);
    template <class U> friend Tensor<U> operator+ (const U& a, const Tensor<U>& A);
    template <class U> friend Tensor<U> operator+ (const Tensor<U>& A, const U& a);

    // operator -
    template <class U> friend Tensor<U> operator- (const Tensor<U>& A, const Tensor<U>& B);
    template <class U> friend Tensor<U> operator- (const U& a, const Tensor<U>& A);
    template <class U> friend Tensor<U> operator- (const Tensor<U>& A, const U& a);

    // operator ==
    bool operator== (const Tensor<T>& B);
    bool compare (const Tensor<T>& B, double tolerance);
    

    // operator *
    template <class U> friend Tensor<U> operator* (const Tensor<U>& A, const Tensor<U>& B);
    template <class U> friend Tensor<U> operator* (const U& a, const Tensor<U>& A);
    template <class U> friend Tensor<U> operator* (const Tensor<U>& A, const U& a);
    
    // elementwise multiplication
     
    // transpose
    
    void multAdd(int i, int j, T multFactor);  //mat
    void resize(int row, int col); //mat
    void join(const bMatrix<T>& B); 
    void swapRow(int i, int j); //mat
    void seperate(bMatrix<T> *A, bMatrix<T> *B, int colNum); //mat
    void multRow(int i, T multFactor); //mat
   
    // inverse
    void inverse(); //mat

    // determinate
    T det(); //mat
       
    //******Element access*************
 
    int sub2Ind(int row, int col); //mat

    int findRowWithMaxElement( int colNumber, int startingRow); //mat
   
    // Setters
    void setElement(int row, int col, T value);
    void setElement(int index, T value);

    // maybe operator >>

    // getters
    T getElement(int row, int col);
    T getElement(int index);
    
    // operator ()
    T operator() (int index);
    T operator() (int row, int col);

    bMatrix<T> findSubMatrix(int rowNum, int colNum); //mat

    // seq

    // head

    // tail

    // getRow

    // getCol

    //***********Describing**************** 
    std::string getType();

    void describe(); 

    int getNumRows(); //mat
    int getNumCols(); //mat

    void print(); 
    bool isSquare(); //mat

    bool closeEnough(T f1, T f2); //mat

    // operator <<
    template <class U> friend std::ostream& operator<< (std::ostream& out, const Tensor<U> A);
    
    // isSparse()

 private:
    T *m_Data;
    int  m_nElements;

};

#include "constructors.inl"

#include "elementAccess.inl"

#include "matrixOperations.inl"

#include "describing.inl"


#endif