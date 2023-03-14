// Geters

template <class T>
int bMatrix<T>::sub2Ind(int row, int col)
{
    // add some assertions
    return (col * m_nRows) + row;
}

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