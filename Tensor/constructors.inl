//////////////////////////////////////////////
// Constructors and destructors

// desctructor
template <class T>
bMatrix<T>::~bMatrix()
{
    if (m_matrixData != nullptr)
        delete[] m_matrixData;
}

// default constructor
template <class T>
bMatrix<T>::bMatrix()
{
    m_nElements =1;
    m_matrixData = new T[m_nElements];
    m_matrixData[0] = 0.0;
}


