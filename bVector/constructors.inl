
// desctructor
template <class T>
bVector<T>::~bVector()
{
    
}

// default constructor
template <class T>
bVector<T>::bVector(std::string type)
{
    m_length = 1;
    m_type = type;
    m_vectorData = std::vector<T>();
}

// std::vector as input
template <class T>
bVector<T>::bVector(std::vector<T> inputData, std::string type)
{
    m_length = inputData.size();
    m_vectorData = inputData;
    m_type = type;   
}