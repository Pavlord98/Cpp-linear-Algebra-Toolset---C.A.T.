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

template <class T>
bool bMatrix<T>::isRowEchelon()
{
    bool flag = true;
    for (int i=1; i<m_nRows; i++)
    {
        for (int j=0; j<i; j++)
        {
            if (m_matrixData[sub2Ind(i,j)] != static_cast<T>(0.0))
                flag = false;
        }
    }    
    return flag;
}

template <class T>
bool bMatrix<T>::isSquare()
{
    if (this->getNumRows() == this->getNumCols())
        return true;
    else
        return false;
}

template <class T>
bool bMatrix<T>::isDiagDom()
{
    bool flag = true;
    for (int i=0; i<this->getNumRows(); i++)
    {
        T aii = this->getElement(i,i);
        T sum = static_cast<T>(0.0);
        for(int j=0; j<this->getNumCols(); j++)
        {
            if(i != j)
                sum += abs(this->getElement(i,j));
        }
        if (abs(aii) < sum)
            flag = false;
    }
    return flag;
}

template <class T>
bool bMatrix<T>::isSym()
{
    bool flag = true;
    bMatrix<T> B = this->transpose();
    for(int i=0; i < m_nElements; i++)
    {
        if (this->getElement(i) != B.getElement(i))
        {
            flag = false;
            return flag;
        }
    }
    return flag;
}

template <class T>
bool bMatrix<T>::isPositive()
{
    bool flag = true;
    for (int i = 0; i< this->getNumRows(); i++)
    {
        if (this->getElement(i,i) < 0)
        {
            flag = false;
            return flag;
        }
    }
    return flag;
}

template <class T>
T bMatrix<T>::minElement()
{
    T min = this->getElement(0);
    for (int i = 0; i < this->getNumRows() * this->getNumCols(); i++)
    {
        if (this->getElement(i) < min)
            min = this->getElement(i);
    }
    return min;
}

template <class T>
T bMatrix<T>::maxElement()
{
    T max = this->getElement(0);
    for (int i = 0; i < this->getNumRows() * this->getNumCols(); i++)
    {
        if (this->getElement(i) > max)
            max = this->getElement(i);
    }
    return max;
}