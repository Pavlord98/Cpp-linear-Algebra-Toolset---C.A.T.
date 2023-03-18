#include <iostream>
#include "bMatrix.h"
#include "bVector.h"

int main()
{

    std::vector<double> vec(3);

    bVector<double> a(vec);

    bVector<double> b(vec);

    a.setElement(0,10.1);

    b.setElement(0,9.1);

    //std::cout<<a.getElement(3)<<'\n';

    a.print(); 

    bMatrix<double> A(3,3,"ones");

    bVector<double> rez = A*a;

    return 0;
}