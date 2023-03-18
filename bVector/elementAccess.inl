// Geters

template <class T>
T bVector<T>::getElement(int index) const
{
    // assert da index nije negativan
    return m_vectorData[index];
}


template <class T>
void bVector<T>::setElement(int index, T value)
{
    m_vectorData[index] = value;
}