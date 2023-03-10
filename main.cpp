#include <iostream>
#include "bMatrix.h"

int main()
{
    bMatrix<int> A(3,3);

    A.setElement(2, 3);

    A.setElement(3, 4);

    A.setElement(1, 4);

    A.setElement(0,4);


    bMatrix<int> B(3,3);

    B.setElement(2, 4);

    B.setElement(3, 4);

    B.setElement(1, 4);

    B.setElement(0,4);

    //bMatrix<int> C{3-B};

    //bMatrix<int> D(A*B);


    bMatrix<int> A2(A);
    
    
    bMatrix<int> F(2,2);

    F.setElement(0,1, 1);

    std::cout << F.getElement(1) << '\n';

    B.setElement(1,1,6);
    B.setElement(5,7);

    A.print();

    B.print();

    //(A*B).print();

    std::cout << "B" << B;

    std::cout << "5*B" << B*5;

    std::cout << B.getType()<< '\n';

    return 0;
}