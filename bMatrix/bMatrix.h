#ifndef BMATRIX_H
#define BMATRIX_H

#include <string>
#include <typeinfo>
#include <iostream>

#include <stdexcept>
#include <math.h>
#include <vector>

template <class T>
class bMatrix
{
 public:
    //******Constructors*************
    bMatrix();
    bMatrix(int nRows, int nCols);
    bMatrix(int nRows, int nCols, const T *inputData);
    bMatrix(const bMatrix<T>& inputData);
    bMatrix(int nRows, int nCols, const std::vector<T> *inputData);

    bMatrix(int nRows, int nCols, std::string type);
    
    ~bMatrix();


    //******Matrix operations*************
    // operator =
    //template <class U> friend bMatrix<U> operator= (const bMatrix<U>& A, const bMatrix<U>& B);

    // operator +
    template <class U> friend bMatrix<U> operator+ (const bMatrix<U>& A, const bMatrix<U>& B);
    template <class U> friend bMatrix<U> operator+ (const U& a, const bMatrix<U>& A);
    template <class U> friend bMatrix<U> operator+ (const bMatrix<U>& A, const U& a);

    // operator -
    template <class U> friend bMatrix<U> operator- (const bMatrix<U>& A, const bMatrix<U>& B);
    template <class U> friend bMatrix<U> operator- (const U& a, const bMatrix<U>& A);
    template <class U> friend bMatrix<U> operator- (const bMatrix<U>& A, const U& a);

    // operator ==
    bool operator== (const bMatrix<T>& B);
    bool compare (const bMatrix<T>& B, double tolerance);
    

    // operator *
    template <class U> friend bMatrix<U> operator* (const bMatrix<U>& A, const bMatrix<U>& B);
    template <class U> friend bMatrix<U> operator* (const U& a, const bMatrix<U>& A);
    template <class U> friend bMatrix<U> operator* (const bMatrix<U>& A, const U& a);
    
    // elementwise multiplication
     
    // transpose
    
    // inverse


    //******Indexing (and slicing)*************    
    //******Element access*************
 
    int sub2Ind(int row, int col);
    void resize(int row, int col);
    bool isSquare();
    bool closeEnough(T f1, T f2);
    void swapRow(int i, int j);
    void multAdd(int i, int j, T multFactor);
    void join(const bMatrix<T>& B);
    int findRowWithMaxElement( int colNumber, int startingRow);
    void seperate(bMatrix<T> *A, bMatrix<T> *B, int colNum);

 public:
    
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

    // seq

    // head

    // tail

    // getRow

    // getCol

    //***********Describing**************** 
    std::string getType();

    void describe(); 

    int getNumRows();
    int getNumCols();

    void print();

    // operator <<
    template <class U> friend std::ostream& operator<< (std::ostream& out, const bMatrix<U> A);
    
    // isSparse()

 private:
    

    T *m_matrixData;
    int m_nRows, m_nCols, m_nElements;

};

#include "constructors.inl"

#include "elementAccess.inl"

#include "matrixOperations.inl"

#include "describing.inl"


#endif