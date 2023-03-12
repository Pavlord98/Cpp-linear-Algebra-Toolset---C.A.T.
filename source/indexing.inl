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