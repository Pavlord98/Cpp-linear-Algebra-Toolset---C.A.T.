#ifndef BMATRIX_H
#define BMATRIX_H

#include <string>
#include <typeinfo>
#include <iostream>

template <class T>
class bMatrix
{
 public:
    bMatrix();
    bMatrix(int nRows, int nCols);
    bMatrix(int nRows, int nCols, const T *inputData);
    bMatrix(const bMatrix<T>& inputData);
    
    ~bMatrix();

    // Getters
    T getElement(int row, int col);
    T getElement(int index);
    
    int getNumRows();
    int getNumCols();

    /*
    struct shape
    {
        int nRows;
        int nCols;
    }
    shape Shape();

    std::string getType();

    void describe(); 
    */

    // Setters
    void setElement(int row, int col, T value);
    void setElement(int index, T value);


    //////////////////////////
    // operator overloads
        
    // operator +
    template <class U> friend bMatrix<U> operator+ (const bMatrix<U>& A, const bMatrix<U>& B);
    template <class U> friend bMatrix<U> operator+ (const U& a, const bMatrix<U>& A);
    template <class U> friend bMatrix<U> operator+ (const bMatrix<U>& A, const U& a);

    // operator -
    template <class U> friend bMatrix<U> operator- (const bMatrix<U>& A, const bMatrix<U>& B);
    template <class U> friend bMatrix<U> operator- (const U& a, const bMatrix<U>& A);
    template <class U> friend bMatrix<U> operator- (const bMatrix<U>& A, const U& a);

    // operator ==
    //template <class U> friend bMatrix<U> operator== (const bMatrix<U>& A);

    // operator *
    template <class U> friend bMatrix<U> operator* (const bMatrix<U>& A, const bMatrix<U>& B);
    template <class U> friend bMatrix<U> operator* (const U& a, const bMatrix<U>& A);
    //template <class U> friend bMatrix<U> operator* (const bMatrix<U>& A, const U& a);
    
    // operator []
     
    // operator <<
    template <class U> friend std::ostream& operator<< (std::ostream& out, const bMatrix<U> A);
    
    // maybe operator >>

    ///////////////////////////

    void print();

    ///////////////////////
    // indexing and slicing
    ///////////////////////

    // elementwise multiplication 
     

 private:
    int sub2Ind(int row, int col);

    T *m_matrixData;
    int m_nRows, m_nCols, m_nElements;

};

//////////////////////////////////////////////
// Constructors and destructors

// default constructor
template <class T>
bMatrix<T>::bMatrix()
{
    m_nRows =1;
    m_nCols =1;
    m_nElements =1;
    m_matrixData = new T[m_nElements];
    m_matrixData[0] = 0.0;
}

// constructor of a empty matrix with specified dimensions
template <class T>
bMatrix<T>::bMatrix(int nRows, int nCols)
{
    m_nRows=nRows;
    m_nCols=nCols;
    m_nElements =m_nRows*m_nCols;
    m_matrixData = new T[m_nElements];
    for (int i =0; i<m_nElements; i++)
        m_matrixData[i] = 0.0;
}

// constructor with array
template <class T>
bMatrix<T>::bMatrix(int nRows, int nCols, const T *inputData)
{
    // add a check for size here
    m_nRows =nRows;
    m_nCols =nCols;
    m_nElements =m_nRows*m_nCols;
    m_matrixData = new T[m_nElements];
    for (int i =0; i<m_nElements; i++)
        m_matrixData[i] = inputData[i];
}


// copy constructor
template <class T>
bMatrix<T>::bMatrix(const bMatrix<T>& inputData)
{
    m_nRows =inputData.m_nRows;
    m_nCols =inputData.m_nCols;
    m_nElements =inputData.m_nRows * inputData.m_nCols;
    m_matrixData = new T[m_nElements];
    for (int i =0; i<m_nElements; i++)
        m_matrixData[i] = inputData.m_matrixData[i];
}



template <class T>
bMatrix<T>::~bMatrix()
{
    if (m_matrixData != nullptr)
        delete[] m_matrixData;
}

//////////////////////////////////////////////
// Geters

template <class T>
T bMatrix<T>::getElement(int index)
{
    // assert da index nije negativan
    return m_matrixData[index];
}

template <class T>
T bMatrix<T>::getElement(int row, int col)
{
    // assert da index nije negativan
    return m_matrixData[sub2Ind(row, col)];
}

template <class T>
int bMatrix<T>::getNumRows()
{
    return m_nRows;
}

template <class T>
int bMatrix<T>::getNumCols()
{
    return m_nCols;
}

//////////////////////////////////////////////

//////////////////////////////////////////////
// Setters

template <class T>
void bMatrix<T>::setElement(int index, T value)
{
    // assertion
    m_matrixData[index] = value;
}

template <class T>
void bMatrix<T>::setElement(int row, int col, T value)
{
    // assertions
    m_matrixData[sub2Ind(row, col)] = value;
}

//////////////////////////////////////////////
// operators

// add assertions in all of these later

// matrix + matrix
template <class T>
bMatrix<T> operator+ (const bMatrix<T>& A, const bMatrix<T>& B)
{
    int nRows = A.m_nRows;
    int nCols = A.m_nCols;
    int numElements = nRows * nCols;
    T *temp = new T[numElements];
    for(int i = 0; i<numElements; i++)
    {
        temp[i] = A.m_matrixData[i] + B.m_matrixData[i];
    }
    bMatrix<T> result(nRows,nCols, temp);
    delete[] temp;
    return result;
}

// matrix + scalar
template <class T>
bMatrix<T> operator+ (const bMatrix<T>& A, const T& a)
{
    int nRows = A.m_nRows;
    int nCols = A.m_nCols;
    int numElements = nRows * nCols;
    T *temp = new T[numElements];
    for(int i = 0; i<numElements; i++)
    {
        temp[i] = A.m_matrixData[i] + a;
    }
    bMatrix<T> result(nRows,nCols, temp);
    delete[] temp;
    return result;
}

// scalar + matrix
template <class T>
bMatrix<T> operator+ (const T& a, const bMatrix<T>& A)
{
    int nRows = A.m_nRows;
    int nCols = A.m_nCols;
    int numElements = nRows * nCols;
    T *temp = new T[numElements];
    for(int i = 0; i<numElements; i++)
    {
        temp[i] = A.m_matrixData[i] + a;
    }
    bMatrix<T> result(nRows,nCols, temp);
    delete[] temp;
    return result;
}

// matrix - matrix
template <class T>
bMatrix<T> operator- (const bMatrix<T>& A, const bMatrix<T>& B)
{
    int nRows = A.m_nRows;
    int nCols = A.m_nCols;
    int numElements = nRows * nCols;
    T *temp = new T[numElements];
    for(int i = 0; i<numElements; i++)
    {
        temp[i] = A.m_matrixData[i] - B.m_matrixData[i];
    }
    bMatrix<T> result(nRows,nCols, temp);
    delete[] temp;
    return result;
}

// matrix - scalar
template <class T>
bMatrix<T> operator- (const bMatrix<T>& A, const T& a)
{
    int nRows = A.m_nRows;
    int nCols = A.m_nCols;
    int numElements = nRows * nCols;
    T *temp = new T[numElements];
    for(int i = 0; i<numElements; i++)
    {
        temp[i] = A.m_matrixData[i] - a;
    }
    bMatrix<T> result(nRows,nCols, temp);
    delete[] temp;
    return result;
}

// scalar - matrix (dunno if this makes sense)
template <class T>
bMatrix<T> operator- (const T& a, const bMatrix<T>& A)
{
    int nRows = A.m_nRows;
    int nCols = A.m_nCols;
    int numElements = nRows * nCols;
    T *temp = new T[numElements];
    for(int i = 0; i<numElements; i++)
    {
        temp[i] =  a - A.m_matrixData[i];
    }
    bMatrix<T> result(nRows,nCols, temp);
    delete[] temp;
    return result;
}

// matrix * matrix
template <class T>
bMatrix<T> operator * (const bMatrix<T>& A, const bMatrix<T>& B)
{
    // assertions
    T * tempResult = new T[A.m_nRows * B.m_nCols];

    // loop through rows A
    for (int i=0; i < A.m_nRows; i++)
    {
        // loop through columns of B
        for (int j=0; j < B.m_nCols; j++)
        {
            T elementResult = 0.0;
            //loop through each element of this A row
            for (int k=0; k<A.m_nCols; k++)
            {
                int Aindex = k*A.m_nRows + i;

                int Bindex = j*B.m_nRows + k;

                elementResult += (A.m_matrixData[Aindex] * B.m_matrixData[Bindex]); 
            }

            // Store the result
            int resultIdex = (A.m_nRows * j) + i;
            tempResult[resultIdex] = elementResult;

        }    
    }
    bMatrix<T> result(A.m_nRows, B.m_nCols, tempResult);
    delete tempResult;
    return result;
}

template <class T>
bMatrix<T> operator* (const T& a, const bMatrix<T>& A)
{
    //assertions

    T * tempresult = new T[A.m_nCols*A.m_nRows];

    for (int i=0; i<A.m_nCols*A.m_nRows; i++)
    {
        T[i] = A.m_matrixData[i] * a; 
    }
    bMatrix<T> result(A.m_nRows, B.m_nCols, tempResult);
    delete tempResult;
    return result;
}

template <class T>
int bMatrix<T>::sub2Ind(int row, int col)
{
    // add some assertions
    return (col * m_nRows) + row;
}

template <class T>
void bMatrix<T>::print()
{
    std::cout<< "=\n";
    for (int i=0; i<m_nRows; i++)
    {
        for (int j=0; j<m_nCols; j++)
        {
            std::cout << m_matrixData[j*m_nRows+i] << "    ";
        }
        std::cout << '\n';
    }   
}

template <class T>
std::ostream& operator<< (std::ostream& out, const bMatrix<T> A)
{
    out << "=\n";
    for (int i=0; i<A.m_nRows; i++)
    {
        for (int j=0; j<A.m_nCols; j++)
        {
            out << A.m_matrixData[j*A.m_nRows+i] << "    ";
        }
        out << '\n';
    }
    return out;
}



#endif