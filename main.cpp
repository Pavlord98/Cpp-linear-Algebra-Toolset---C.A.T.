#include <iostream>
#include "bMatrix.h"

int main()
{
    
    bMatrix<double> A(3,3);
    
    A.setElement(0,2.0);
    A.setElement(1,1.0);
    A.setElement(2,0.0);
    A.setElement(3,1.0);
    A.setElement(4,0.0);
    A.setElement(5,3.0);
    A.setElement(6,1.0);
    A.setElement(7,1.0);
    A.setElement(8,1.0);

    //std::cout << A; // this somehow messes up the inversion
    A.print();


    A.inverse();

    std::cout << A;

    

    return 0;
}