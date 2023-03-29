
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
void bMatrix<T>::joinHor(const bMatrix<T>& B)
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
void bMatrix<T>::joinVert(const bMatrix<T>& B)
{
    // get size
    int numRows1 = m_nRows;
    int numRows2 = B.m_nRows;
    int numCols1 = m_nCols;
    int numCols2 = B.m_nCols;

    // check dimensions
    if (numCols1 != numCols2)
        throw std::invalid_argument("incompatable sizes!");

    // Allocate memory for the result
    T* newMatrixData = new T[numCols1*(numRows1 + numRows2)];

    // copy the two matrices into the new one
    int index, resultIndex;
    for (int j=0; j<numCols1; j++)
    {
        for (int i=0; i<(numRows1 +numRows2); i++)
        {
            resultIndex = j*(numRows1+numRows2) + i;
            if (i<numRows1)
            {
                index = j*(numRows1) + i;
                newMatrixData[resultIndex] = m_matrixData[index];
            }
            else
            {
                index = j*(numRows2) + i - numRows1;
                newMatrixData[resultIndex] = B.m_matrixData[index];
            }
        }
    }

    //update stored data
    m_nRows = numRows1 + numRows2;
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

template <class T>
void bMatrix<T>::multRow(int i, T multFactor)
{
    for (int k=0; k<m_nCols; k++)
        m_matrixData[sub2Ind(i,k)] *= multFactor;
}

template <class T>
void bMatrix<T>::inverse()
{

    std::cout << "starting from: ";
    this->print();
    // form an indentity matrix with the same dimensions so we can begin
    bMatrix<T> IdentiyMatrix(m_nRows, m_nCols, "eye");

    // join the identity matrix to the existing matrix
    int originalNumCols = m_nCols;
    joinHor(IdentiyMatrix);

    // begin main part of the process
    int cRow, cCol;
    int maxCount = 100;
    int count = 0;
    bool completeFlag = false;
    while((!completeFlag) && (count < maxCount))
    {
        for (int diagIndex = 0; diagIndex<m_nRows; diagIndex++)
        {
            cRow = diagIndex;
            cCol = diagIndex;

            // find the index of the maximum element in the current column
            int maxIndex = findRowWithMaxElement(cCol, cRow);

            //if this isn't the current row, then swap
            if (maxIndex != cRow)
            {
                swapRow(cRow, maxIndex);
            }

            // make sure the value at (cRow, cCol) is equal to one
            if (m_matrixData[sub2Ind(cRow,cCol)] != 1.0)
            {
                T multFactor = 1.0 / m_matrixData[sub2Ind(cRow,cCol)];
                multRow(cRow, multFactor);
            }

            // consider the column
            for (int rowIndex=cRow+1; rowIndex<m_nRows; rowIndex++)
            {
                if (!closeEnough(m_matrixData[sub2Ind(rowIndex,cCol)], 0.0))
                {
                    int rowOneIndex = cCol;

                    T currentElementValue = m_matrixData[sub2Ind(rowIndex, cCol)];

                    T rowOneValue = m_matrixData[sub2Ind(rowOneIndex, cCol)];

                    if (!closeEnough(rowOneValue, 0.0))
                    {
                        T correctionFactor = - (currentElementValue / rowOneValue);

                        multAdd(rowIndex, rowOneIndex, correctionFactor);
                    }
                }
            }

            // consider the row
            for (int colIndex = cCol+1; colIndex<originalNumCols; colIndex++)
            {
                if (!closeEnough(m_matrixData[sub2Ind(cRow, colIndex)], 0.0))
                {
                    int rowOneIndex = colIndex;

                    T currentElementValue = m_matrixData[sub2Ind(cRow, colIndex)];
                    T rowOneValue = m_matrixData[sub2Ind(rowOneIndex, colIndex)];

                    if (!closeEnough(rowOneValue, 0.0))
                    {
                        T correctionFactor = -(currentElementValue / rowOneValue);

                        multAdd(cRow, rowOneIndex,correctionFactor);
                    }
                }
            }

            
        }
        // seperate the result into left and right halves 
            bMatrix<T> leftHalf;
            bMatrix<T> rightHalf;
            this->seperate(&leftHalf, &rightHalf, originalNumCols);

            std::cout<< leftHalf;

            if (leftHalf == IdentiyMatrix)
            {
                std::cout << "completed\n";
                completeFlag = true;

                m_nCols = originalNumCols;
                m_nElements = m_nRows * m_nCols;
                delete[] m_matrixData;
                m_matrixData = new T[m_nElements];
                for (int i=0;i<m_nElements; i++)
                    m_matrixData[i] = rightHalf.m_matrixData[i];
            }

            count++;
    }
    
}

template <class T>
bMatrix<T> bMatrix<T>::rowEchelon()
{
    int cRow, cCol;
    int maxCount = 100;
    int count = 0;
    bool completeFlag = false;

    bMatrix<T> A(m_nRows,m_nCols, m_matrixData);

    while ((!completeFlag) && (count < maxCount))
    {
        for (int diagIndex=0; diagIndex < m_nRows; diagIndex++)
        {
            cRow = diagIndex;
            cCol = diagIndex;

            for (int rowIndex = cRow+1; rowIndex<m_nRows; rowIndex++)
            {
                if (!closeEnough(A.m_matrixData[sub2Ind(rowIndex, cCol)], 0.0))
                {
                    int rowOneIndex = cCol;

                    T currentElementValue = A.m_matrixData[sub2Ind(rowIndex, cCol)];
                    T rowOneValue = A.m_matrixData[sub2Ind(rowOneIndex, cCol)];   

                    if(!closeEnough(rowOneValue, 0.0))
                    {
                        T correctionFactor = -(currentElementValue/rowOneValue);
                        A.multAdd(rowIndex, rowOneIndex, correctionFactor);
                    } 
                }
            }
        }
        completeFlag = this->isRowEchelon();  
        count++;
    }  
    bMatrix<T> outputMatrix(m_nRows, m_nCols, A.m_matrixData);
    return outputMatrix;
}

template <class T>
bMatrix<T> bMatrix<T>::transpose() const
{
    bMatrix<T> Result(this->getNumRows(), this->getNumCols());
    for (int i=0; i < this->getNumRows(); i++)
    {
        for (int j=0; j < this->getNumCols(); j++)
        {
            Result.setElement(j,i, this->getElement(i,j));
        }
    }
    return Result;
}
