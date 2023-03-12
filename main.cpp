#include <iostream>
#include "bMatrix.h"

int main()
{
    bMatrix<double> F(5,5,"eye");

    std::cout << F;

    return 0;
}