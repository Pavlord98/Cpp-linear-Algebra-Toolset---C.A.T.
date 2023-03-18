
// desctructor
template <class T>
bVector<T>::~bVector()
{
    
}

// default constructor
template <class T>
bVector<T>::bVector()
{
    m_length = 0;
    m_vectorData = std::vector<T>();
}

// std::vector as input
template <class T>
bVector<T>::bVector(std::vector<T> inputData)
{
    m_length = inputData.size();
    m_vectorData = inputData; 
}