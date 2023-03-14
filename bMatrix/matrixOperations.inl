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

// sclar * matrix
template <class T>
bMatrix<T> operator* (const T& a, const bMatrix<T>& A)
{
    //assertions

    T * tempResult = new T[A.m_nCols*A.m_nRows];

    for (int i=0; i<A.m_nCols*A.m_nRows; i++)
    {
        tempResult[i] = A.m_matrixData[i] * a; 
    }
    bMatrix<T> result(A.m_nRows, A.m_nCols, tempResult);
    delete tempResult;
    return result;
}

// matrix * scalar
template <class T>
bMatrix<T> operator* (const bMatrix<T>& A, const T& a)
{
    //assertions

    T * tempResult = new T[A.m_nCols*A.m_nRows];

    for (int i=0; i<A.m_nCols*A.m_nRows; i++)
    {
        tempResult[i] = A.m_matrixData[i] * a; 
    }
    bMatrix<T> result(A.m_nRows, A.m_nCols, tempResult);
    delete tempResult;
    return result;
}