#include <iostream>
#include "bMatrix.h"
#include "bVector.h"

int main()
{
    
    bMatrix<double> A(3,3);
    
    A.setElement(0,8.0);
    A.setElement(1,3.0);
    A.setElement(2,4.0);
    A.setElement(3,1.0);
    A.setElement(4,5.0);
    A.setElement(5,9.0);
    A.setElement(6,6.0);
    A.setElement(7,7.0);
    A.setElement(8,2.0);

    //std::cout << A; // this somehow messes up the inversion
    A.print();


    bMatrix<double> B(A.findSubMatrix(1,1));

    std::cout << A.det();

    bVector<double> a();

    return 0;
}