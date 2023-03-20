#include <iostream>
#include "bMatrix.h"
#include "bVector.h"
#include "gaussElim.h"

int main()
{

    double array[9] = {2,1,4,3,4,0,1,1,7};

    bMatrix<double> A(3,3,array);

    A.print();

    bMatrix<double> B = A.transpose();

    B.print();

    return 0;

    
}

