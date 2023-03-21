#include <iostream>
#include "bMatrix.h"
#include "bVector.h"
#include "gaussElim.h"
#include "gaussSeidel.h"

int main()
{

    double array[16] = {10, -1, 2, 0, -1, 11, -1, 3, 2, -1, 10, -1, 0, 3, -1, 8};

    bMatrix<double> A(4,4,array);

    A.print();

    double array2[4] = {6, 25, -11, 15};

    bMatrix<double> b(4,1, array2);

    b.print();

    bMatrix<double> result = gaussSeidel(A, b);
    
    //bMatrix<double> result = A*b - b;

    result.print();

    return 0;
}

