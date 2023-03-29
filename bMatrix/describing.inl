template <class T>
void bMatrix<T>::print() const
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
int bMatrix<T>::getNumRows() const
{
    return m_nRows;
}

template <class T>
int bMatrix<T>::getNumCols() const
{
    return m_nCols;
}

template <class T>
bool bMatrix<T>::closeEnough(T f1, T f2) const
{
    return fabs(f1-f2) < 1e-9;
}

template <class T>
bool bMatrix<T>::isRowEchelon() const
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
bool bMatrix<T>::isSquare() const
{
    if (this->getNumRows() == this->getNumCols())
        return true;
    else
        return false;
}

template <class T>
bool bMatrix<T>::isDiagDom() const
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
bool bMatrix<T>::isSym() const
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
bool bMatrix<T>::isPositive() const
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
T bMatrix<T>::minElement() const
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
T bMatrix<T>::maxElement() const
{
    T max = this->getElement(0);
    for (int i = 0; i < this->getNumRows() * this->getNumCols(); i++)
    {
        if (this->getElement(i) > max)
            max = this->getElement(i);
    }
    return max;
}

template <class T>
double bMatrix<T>::L1Norm() const
{
    double sum = 0;
    for (int i=0; i<m_nElements; i++)
    {
        sum += abs(this->getElement(i));
    }
    return sum/m_nElements;
}

template <class T>
double bMatrix<T>::L2Norm() const
{
    double sum = 0;
    for (int i=0; i<m_nElements; i++)
    {
        sum += this->getElement(i) * this->getElement(i);
    }
    return sqrt(sum/m_nElements); 
}

template <class T>
T bMatrix<T>::LInfNorm() const
{
    return abs(this->maxElement());   
}

template <class T>
T bMatrix<T>::det()
{
    // some assertions

    T determinant;
    if (m_nRows == 2)
    {
        determinant = (m_matrixData[0] * m_matrixData[3]) - (m_matrixData[1] * m_matrixData[2]);
    }
    else 
    {
        T cumSum = 0.0;
        T sign = 1.0; // try int
        for (int j=0; j<m_nCols; j++)
        {
            bMatrix<T> subMatrix(this->findSubMatrix(0,j));
            cumSum += this->getElement(0,j) * subMatrix.det() * sign;
            sign = -sign;
        }
        determinant = cumSum;
    }
    return determinant;
}
