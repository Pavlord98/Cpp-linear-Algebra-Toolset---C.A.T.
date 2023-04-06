#include <iostream>
#include "bMatrix.h"
#include "bVector.h"
#include "gaussElim.h"
#include "gaussSeidel.h"
<<<<<<< Updated upstream
=======
#include "gaussSeidelSym.h"

#include "conjugateGradient.h"

#include "Solver.h"
#include "jacobi.h"
#include <memory>
>>>>>>> Stashed changes

int main()
{

    double array[16] = {10, -1, 2, 0, -1, 11, -1, 3, 2, -1, 10, -1, 0, 3, -1, 8};

    bMatrix<double> A(4,4,array);

    A.print();

    double array2[4] = {6, 25, -11, 15};

    bMatrix<double> b(4,1, array2);

    b.print();

<<<<<<< Updated upstream
    bMatrix<double> result = gaussSeidel(A, b);
    
    //bMatrix<double> result = A*b - b;
=======
    std::string name{"Jacobi"};

    std::unique_ptr<Solver> solver;
    if(name=="Jacobi")
    {
        solver.reset(new JacobiSolver);
    }
    else if(name == "GaussSeidel")
    {
        solver.reset(new GaussSeidelSolver);
    }
    else
    {

    }
    bMatrix<double> result = solver->solve(A, b);
>>>>>>> Stashed changes

    result.print();

    return 0;
}

