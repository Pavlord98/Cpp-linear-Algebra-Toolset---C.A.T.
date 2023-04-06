#ifndef BMATRIX_H
#define BMATRIX_H

#include <string>
#include <typeinfo>
#include <iostream>

#include <stdexcept>
#include <math.h>
#include <vector>

#include "bVector.h"

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

    //*************Arithmetic******************
    
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
    
    bMatrix<T> operator= (const bMatrix<T> &rhs);

    // operator *
    template <class U> friend bMatrix<U> operator* (const bMatrix<U>& A, const bMatrix<U>& B);
    template <class U> friend bMatrix<U> operator* (const U& a, const bMatrix<U>& A);
    template <class U> friend bMatrix<U> operator* (const bMatrix<U>& A, const U& a);
    
    // matrix * vector
    template <class U> friend bVector<U> operator* (const bMatrix<U>& A, const bVector<U>& b);

    // dot product
    T dot(const bMatrix<T>& b);
    
    // elementwise multiplication
   

    //******Matrix operations*************
    
    // transpose
    bMatrix<T> transpose() const;
    
    void multAdd(int i, int j, T multFactor);  
    void resize(int row, int col);
    void joinHor(const bMatrix<T>& B);
    void joinVert(const bMatrix<T>& B);
    void swapRow(int i, int j);
    void seperate(bMatrix<T> *A, bMatrix<T> *B, int colNum);
    void multRow(int i, T multFactor);
   
    // inverse
    void inverse();

    // get row echelon form
    bMatrix<T> rowEchelon();
       
    //******Element access*************
 
    int sub2Ind(int row, int col) const;

    int findRowWithMaxElement( int colNumber, int startingRow);
   
    // Setters
    void setElement(int row, int col, T value);
    void setElement(int index, T value);

    // maybe operator >>

    // getters
    T getElement(int row, int col) const;
    T getElement(int index) const;
    
    // operator ()
    T operator() (int index);
    T operator() (int row, int col);

    bMatrix<T> findSubMatrix(int rowNum, int colNum);

    // seq

    // head

    // tail

    // getRow

    // getCol

    //***********Describing**************** 
    std::string getType();

    void describe() const; 

    int getNumRows() const;
    int getNumCols() const;

    void print() const;
    bool isSquare() const;
    bool isRowEchelon() const;
    bool isDiagDom() const;
    bool isSym() const;
    bool isPositive() const;

    bool closeEnough(T f1, T f2) const;

    T minElement() const;
    T maxElement() const;

    double L1Norm() const;
    double L2Norm() const;
    T LInfNorm() const;

    // determinate
    T det();
    

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

#include "arithmetic.inl"


#endif