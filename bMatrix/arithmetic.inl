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

// scalar - matrix 
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
    bool flag = true;
    // check the dimensions
    int numRows1 = B.m_nRows;
    int numCols1 = B.m_nCols;
    if ((numRows1 != m_nRows) || (numCols1 != m_nCols) )
    {
            flag = false;
            return flag;
    }    

    // check if the elements are equal
    
    for (int i=0; i < this->m_nElements; i++)
    {
        if (!closeEnough(this->m_matrixData[i], B.m_matrixData[i]))
        {
            flag = false;
            return flag;
        }    
        
        
    }
    return flag;
}

template <class T>
bVector<T> operator* (const bMatrix<T>& A, const bVector<T>& b)
{
    bVector<T> result = b;

    for (int row=0; row<A.m_nRows; row++)
    {
        T cumSum = static_cast<T>(0.0);
        for (int col=0; col<A.m_nCols; col++)
        {
            cumSum += A.getElement(row,col) * b.getElement(col);
        }
        result.setElement(row, cumSum);
    }
    return result;
}

template <class T>
bMatrix<T> bMatrix<T>::operator= (const bMatrix<T> &rhs)
{
	// Make sure we're not assigning to ourself.
	if (this != &rhs)
	{
		// If the dimensions are the same, we only need to copy the elements,
		//	there is no need to delete and re-allocate memory.
		if ((m_nRows == rhs.m_nRows) && (m_nCols == rhs.m_nCols))
		{
			for (int i=0; i<m_nElements; ++i)
				m_matrixData[i] = rhs.m_matrixData[i];
		}
		else
		{
			m_nRows = rhs.m_nRows;
			m_nCols = rhs.m_nCols;
			m_nElements = rhs.m_nElements;
			
			if (m_matrixData)
				delete[] m_matrixData;
			
			m_matrixData = new T[m_nElements];
			for (int i=0; i<m_nElements; i++)
				m_matrixData[i] = rhs.m_matrixData[i];	
		}
	}
	
	return *this;
}

template <class T>
T bMatrix<T>::dot(const bMatrix<T>& b)
{
    T result = static_cast<T>(0.0);
    for (int i=0; i<this->m_nElements; i++)
    {
        result += this->getElement(i) * b.getElement(i);
    }
    return result;
}