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

template <class T>
bool bMatrix<T>::compare(const bMatrix<T>& B, double tolerance)
{
    // check the dimensions
    int numRows1 = B.m_nRows;
    int numCols1 = B.m_nCols;
    if ((numRows1 != m_nRows) || (numCols1 != m_nCols) )
        return false;

    // loop over all elements and compute the sum of squared diffs
    double sum = 0.0;
    for (int i=0; i<m_nElements; i++)
    {
        T element1 = B.m_matrixData[i];
        T element2 = m_matrixData[i];
        sum += (element1 - element2) * (element1 - element2);
    }
    double finalValue = sqrt(sum/((numRows1*numCols1)-1));
    if (finalValue < tolerance)
        return true;
    else
        return false;
}

template <class T>
bool bMatrix<T>::operator== (const bMatrix<T>& B)
{
    // check the dimensions
    int numRows1 = B.m_nRows;
    int numCols1 = B.m_nCols;
    if ((numRows1 != m_nRows) || (numCols1 != m_nCols) )
        return false;

    // check if the elements are equal
    bool flag = true;
    for (int i=0; i < this->m_nElements; i++)
    {
        if (!closeEnough(this->m_matrixData[i], B.m_matrixData[i]))
            flag = false;
    }
}

template <class T>
bool bMatrix<T>::closeEnough(T f1, T f2)
{
    return fabs(f1-f2) < 1e-9;
}

template <class T>
void bMatrix<T>::resize(int row, int col)
{
    m_nRows = row;
    m_nCols = col;
    m_nElements = m_nRows * m_nCols;
    delete[] m_matrixData;
    m_matrixData = new T[m_nElements];
    for (int i=0; i<m_nElements; i++)
        m_matrixData[i] = 0.0;
}

template <class T>
void bMatrix<T>::seperate(bMatrix<T> *A, bMatrix<T> *B, int colNum)
{
    // compute sizes of the new matrices 
    int numRows = m_nRows;
    int numCols1 = colNum;
    int numCols2 = m_nCols - colNum;

    // resize the two matrices
    A->resize(numRows, numCols1);
    B->resize(numRows, numCols2);

    // loop over original matrix and store data into the appropriate elements of the two new matrices
    for (int row=0; row<m_nRows; row++)
    {
        for (int col=0; col<m_nCols; col++)
        {
            if (col<colNum)
            {
                A->setElement(row,col, this->getElement(row,col));
            }
            else 
            {
                B->setElement(row, col-colNum, this->getElement(row,col));
            }
        }
    }

}

template <class T>
void bMatrix<T>::join(const bMatrix<T>& B)
{
    // get size
    int numRows1 = m_nRows;
    int numRows2 = B.m_nRows;
    int numCols1 = m_nCols;
    int numCols2 = B.m_nCols;

    // check dimensions
    if (numRows1 != numRows2)
        throw std::invalid_argument("incompatable sizes!");

    // Allocate memory for the result
    T* newMatrixData = new T[numRows1*(numCols1 + numCols2)];

    // copy the two matrices into the new one
    int index, resultIndex;
    for (int i=0; i<numRows1; i++)
    {
        for (int j=0; j<(numCols1+numCols2); j++)
        {
            resultIndex = j*(numRows1) + i;
            if (j<numCols1)
            {
                index = j*(numRows1) + i;
                newMatrixData[resultIndex] = m_matrixData[index];
            }
            else
            {
                index = (j - numCols1)*numRows1 + i;
                newMatrixData[resultIndex] = B.m_matrixData[index];
            }
        }
    }

    //update stored data
    m_nCols = numCols1 + numCols2;
    m_nElements = m_nRows * m_nCols;
    delete[] m_matrixData;
    m_matrixData = new T[m_nElements];
    for (int i=0; i<m_nElements; i++)
        m_matrixData[i] = newMatrixData[i];
    delete[] newMatrixData;
}

template <class T>
void bMatrix<T>::swapRow(int i, int j)
{
    // Store a temp copy of row i
    T *tempRow = new T[m_nCols];
    for (int k=0; k<m_nCols; k++)   
        tempRow[k] = m_matrixData[i + m_nRows*k];

    // Replace row i with row j
     for (int k=0; k<m_nCols; k++)   
        m_matrixData[i + m_nRows*k] = m_matrixData[j + m_nRows*k];

    // replace row j with the temp vector
    for (int k=0; k<m_nCols; k++)   
        m_matrixData[j + m_nRows*k] = tempRow[k];

    delete[] tempRow;
}

// add multiple of row j to row i
template <class T>
void bMatrix<T>::multAdd(int i, int j, T multFactor)
{
    for (int k=0; k<m_nCols; k++)
        m_matrixData[k*m_nRows + i] += m_matrixData[k*m_nRows + j]*multFactor;
}