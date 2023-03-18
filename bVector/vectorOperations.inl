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