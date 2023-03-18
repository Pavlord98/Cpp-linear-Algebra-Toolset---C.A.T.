// Geters

template <class T>
int bMatrix<T>::sub2Ind(int row, int col) const
{
    // add some assertions
    return (col * m_nRows) + row;
}

template <class T>
T bMatrix<T>::getElement(int index) const
{
    // assert da index nije negativan
    return m_matrixData[index];
}

template <class T>
T bMatrix<T>::getElement(int row, int col) const
{
    // assert da index nije negativan
    return m_matrixData[sub2Ind(row, col)];
}

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

template <class T>
T bMatrix<T>::operator() (int index)
{
    return m_matrixData[index];    
}

template <class T>
T bMatrix<T>::operator() (int row, int col)
{
    return m_matrixData[sub2Ind(row, col)];    
}

template <class T>
int bMatrix<T>::findRowWithMaxElement(int colNumber, int startingRow)
{
    T tempValue = m_matrixData[sub2Ind(startingRow, colNumber)];
    int rowIndex = startingRow;
    for (int k=startingRow; k<m_nRows; k++)
    {
        if (fabs(m_matrixData[sub2Ind(k, colNumber)]) > fabs(tempValue))
        {
            rowIndex = k;
            tempValue = m_matrixData[sub2Ind(k, colNumber)];
        }
    }
    return rowIndex;
}

template <class T>
bMatrix<T> bMatrix<T>::findSubMatrix(int rowNum, int colNum)
{
      bMatrix<T> subMatrix(m_nRows-1, m_nCols-1);
      int count = 0;
      for (int j=0; j<m_nCols; j++)
      {
         for (int i=0; i<m_nRows; i++)
         {
            if ((i != rowNum) && (j != colNum))
            {
               subMatrix.m_matrixData[count] = this->getElement(i,j);
               count++;
            }
         }
      }
      return subMatrix;
}