template <class T>
bVector<T> bVector<T>::operator+ (const bVector<T> &b) const
{
    std::vector<T> resultData(b.size());
    for (int i=0; i<m_length; i++)
        resultData[i] = m_vectorData[i] +  b[i];

    bVector <T> result(resultData);
    return result;
}

template <class T>
bVector<T> bVector<T>::operator- (const bVector<T> &b) const
{
    std::vector<T> resultData(b.size());
    for (int i=0; i<m_length; i++)
        resultData[i] = m_vectorData[i] -  b[i];

    bVector <T> result(resultData);
    return result;
}

template <class T>
bVector<T> bVector<T>::operator* (const T &scalar) const
{
    std::vector<T> resultData(m_length);
    for (int i=0; i<m_length; i++)
        resultData[i] *= scalar;

    bVector<T> result(resultData);
    return result; 
}

template <class T>
bVector<T> operator* (const T &scalar, const bVector<T> &vector)
{
    std::vector<T> resultData(vector.length());
    for(int i=0; i<vector.length; i++)
        resultData[i] = scalar * vector[i];

    bVector<T> result(resultData);
    return result;    
}

template <class T>
T bVector<T>::dot(bVector<T> &a,  bVector<T> &b)
{
    T cumSum = static_cast<T>(0.0);
    for (int i=0; i<a.length(); i++)
        cumSum += a.getElement(i) * b.getElement(i);

    return cumSum;
}

template <class T>
bVector<T> bVector<T>::cross(const bVector<T> &a, const bVector<T> &b)
{
    std::vector<T> resultData(3);

    resultData[0] = a.getElement(1) * b.getElement(2) - a.getElement(2) * b.getElement(1);
    resultData[1] = -(a.getElement(0) * b.getElement(2)) - a.getElement(2) * b.getElement(0);
    resultData[2] = a.getElement(0) * b.getElement(1) - a.getElement(1) * b.getElement(0);

    bVector<T> result(resultData);
    return result;

}

template <class T>
T bVector<T>::norm()
{
    T cumSum = static_cast<T>(0.0);
    for (int i=0; i<m_length; i++)
        cumSum += (m_vectorData[i] * m_vectorData[i]);

    return sqrt(cumSum);
}

template <class T>
bVector<T> bVector<T>::normalized()
{
    T vecNorm = this->norm();
    bVector<T> result(m_vectorData);
    return result * (static_cast<T>(1.0) / vecNorm);
}

template <class T>
void bVector<T>::normalize()
{
    T vecNorm = this->norm();
    for(int i=0; i<m_length; i++)
        m_vectorData[i] *= (static_cast<T>(1.0) / vecNorm);
}