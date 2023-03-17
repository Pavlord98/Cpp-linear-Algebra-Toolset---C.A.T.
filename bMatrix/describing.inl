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

// get type of matrix
template <class T>
std::string bMatrix<T>::getType()
{
    return typeid(m_matrixData[0]).name();   
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

template <class T>
bool bMatrix<T>::closeEnough(T f1, T f2)
{
    return fabs(f1-f2) < 1e-9;
}