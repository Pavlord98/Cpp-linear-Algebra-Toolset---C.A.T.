#include <iostream>
#include "bMatrix.h"

int main()
{
    bMatrix<double> F(5,5,"eye");

    std::cout << F << '\n';

    bMatrix<double> F2(5,5,"eye");

    //std::cout << F.compare(F2-1.0, 0.1) << '\n';

    bMatrix<double> F3(5,5,"eye");

    bMatrix<double>* f3{&F3};

    bMatrix<double>* f2{&F2};

    //std::cout << F==F2;

    F2.multAdd(1,2,5.0);

    std::cout << F2;

    

    return 0;
}