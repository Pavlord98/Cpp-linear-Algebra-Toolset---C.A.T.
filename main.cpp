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

    std::cout<<a.getElement(3)<<'\n';

    std::cout << bVector<double>::dot(a,b) <<'\n'; 

    return 0;
}