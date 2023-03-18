
template <class T>
int bVector<T>::length()
{
    return m_length;
}

template <class T>
void bVector<T>::print()
{
    std::cout<< "=\n";
    for (int i=0; i<m_length; i++)
    {
        std::cout <<  m_vectorData[i] << '\n';
    }   
}