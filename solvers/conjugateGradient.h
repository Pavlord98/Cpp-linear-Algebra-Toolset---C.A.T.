#ifndef CG_H
#define CG_H

#include <iostream>
#include <math.h>
#include <vector>

#include "bMatrix.h"

template <typename T>
bMatrix<T> conjugateGradient( const bMatrix<T>& A, const bMatrix<T>& b, double tolerance = 1e-4, int maxIters=10000, bool verbose = true )
{
    
    int iter = 0;
    
    // Initialize an empty result vector;
    bMatrix<T> X(A.getNumRows(),1); // should add suport for non zero initialization
    bMatrix<T> residual(b); // initial residual
    bMatrix<T> d(residual); // initial search direction

    double delta_new = residual.dot(residual); // inital delta
    double delta0 = delta_new;

    while( sqrt(delta_new/delta0) >= tolerance && iter <= maxIters)
    {
        for (int i=0; i<A.getNumRows(); i++)
        {
            iter++; // count number of iterations

            double alpha = delta_new / d.dot(A*d);  // calculate step size
            X =  X + alpha*d;                       // update the solution
            residual = residual - alpha*(A*d);      // update the residuals
            double delta_old = delta_new;           // save old delta before its update
            delta_new = residual.dot(residual);     // update delta  
            double beta = delta_new / delta_old;    // caclulate beta
            d = residual + beta*d;                  // update search direction
        }
    }

    if (verbose)
    {
        std::cout << "Reached convergence in : " << iter << " iterations\n";
    }

    
    return X;


}


#endif