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
    
    
   

    

    B.setElement(1,1,6);
    B.setElement(5,7);


    //(A*B).print();

    

    bMatrix<double> F(3,3,"bla");

    std::cout << F + 3.0;

    return 0;
}