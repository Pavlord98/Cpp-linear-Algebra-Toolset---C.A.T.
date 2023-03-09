#include <iostream>
#include "bMatrix.h"

int main()
{
    bMatrix<int> A(3,3);
    
    std::cout << A.getElement(2) << '\n';

    A.setElement(2, 3);

    A.setElement(3, 4);

    A.setElement(1, 4);

    A.setElement(0,4);

    std::cout << A.getElement(2) << '\n';

    bMatrix<int> B(3,3);

    B.setElement(2, 4);

    B.setElement(3, 4);

    B.setElement(1, 4);

    B.setElement(0,4);

    bMatrix<int> C{3-B};

    std::cout << C.getElement(2) << '\n';
    
    bMatrix<int> D(A*B);

    std::cout << D.getElement(2) << '\n';

    bMatrix<int> A2(A);
    
    std::cout << A2.getElement(2) << '\n';

    std::cout << "//////////\n";

    bMatrix<int> F(2,2);

    F.setElement(0,1, 1);

    std::cout << F.getElement(1) << '\n';

    return 0;
}