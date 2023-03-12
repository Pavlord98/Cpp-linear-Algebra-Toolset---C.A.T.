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
    m_nRows =1;
    m_nCols =1;
    m_nElements =1;
    m_matrixData = new T[m_nElements];
    m_matrixData[0] = 0.0;
}

// constructor of a empty matrix with specified dimensions
template <class T>
bMatrix<T>::bMatrix(int nRows, int nCols)
{
    m_nRows=nRows;
    m_nCols=nCols;
    m_nElements =m_nRows*m_nCols;
    m_matrixData = new T[m_nElements];
    for (int i =0; i<m_nElements; i++)
        m_matrixData[i] = 0.0;
}

// constructor with array
template <class T>
bMatrix<T>::bMatrix(int nRows, int nCols, const T *inputData)
{
    // add a check for size here
    m_nRows =nRows;
    m_nCols =nCols;
    m_nElements =m_nRows*m_nCols;
    m_matrixData = new T[m_nElements];
    for (int i =0; i<m_nElements; i++)
        m_matrixData[i] = inputData[i];
}

template <class T>
bMatrix<T>::bMatrix(int nRows, int nCols, const std::vector<T> *inputData)
{
    m_nRows = nRows;
    m_nCols = nCols;
    m_nElements = m_nRows * m_nCols;
    m_matrixData = new T[m_nElements];
    for (int i=0; i<m_nElements; i++)
        m_matrixData[i] = inputData->at(i);    
}

// copy constructor
template <class T>
bMatrix<T>::bMatrix(const bMatrix<T>& inputData)
{
    m_nRows =inputData.m_nRows;
    m_nCols =inputData.m_nCols;
    m_nElements =inputData.m_nRows * inputData.m_nCols;
    m_matrixData = new T[m_nElements];
    for (int i =0; i<m_nElements; i++)
        m_matrixData[i] = inputData.m_matrixData[i];
}

//  enum for special initialization
enum init_code
{
    zeros,
    ones,
    eye,
    error,
};

// hash string to enum
init_code hashit (std::string const& inputString)
{
    if (inputString == "zeros") return zeros;
    if (inputString == "ones" ) return ones;
    if (inputString == "eye")   return eye;
    else return error; 
}

// special constructor
template <class T>
bMatrix<T>::bMatrix(int nRows, int nCols, std::string init_code)
{
    // add a check for size here
    m_nRows =nRows;
    m_nCols =nCols;
    m_nElements =m_nRows*m_nCols;
    m_matrixData = new T[m_nElements];
    
    switch (hashit(init_code))
    {
    case zeros:
        for (int i =0; i<m_nElements; i++)
        m_matrixData[i] = static_cast<T>(0.0);
        break;
    case ones :
        for (int i =0; i<m_nElements; i++)
        m_matrixData[i] = static_cast<T>(1.0);
        break;
    case eye:
    for (int i =0; i<m_nElements; i+= nRows + 1)
        m_matrixData[i] = static_cast<T>(1.0);
        break;
    default:
        break;
    }
           
}

