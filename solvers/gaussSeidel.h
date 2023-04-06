#ifndef GAUSSSEIDEL_H
#define GAUSSSEIDEL_H

#include <iostream>
#include <math.h>
#include <vector>

#include "bMatrix.h"
#include "Solver.h"

class GaussSeidelSolver : public Solver
{
public:
    bMatrix<double> solve( const bMatrix<double>& A, const bMatrix<double>& b) //,  double alpha = 1 ,double tolerance = 1e-4, int maxIters=10000, bool verbose = true 
    {
        
        double alpha = 1; double tolerance = 1e-4; int maxIters=10000; bool verbose = true; 

        if ( !A.isDiagDom() || !A.isSym() || !A.isPositive() )
            throw "Incompatible matrix input! Matrix must be diagonally dominant, symetric and positive!";
        
    
        // Initialize an empty result vector;
        bMatrix<double> res(A.getNumRows(),1); // should add suport for non zero initialization

        double temp, tempSum;
        
        bMatrix<double> error(A.getNumRows(),1,"ones");
        int iter = 0;

        while( error.L2Norm() >= tolerance && iter <= maxIters)
        {
            for (int i = 0; i < A.getNumRows(); i++)
            {
                tempSum = 0;
                temp = 0;
                for(int j = 0; j < A.getNumCols(); j++)
                {
                    if (i != j)
                        tempSum += A.getElement(i,j)*res.getElement(j);
                }
                
                temp = (1 - alpha)*res.getElement(i) + alpha/A.getElement(i,i) * (b.getElement(i) - tempSum);
                res.setElement(i, 0, temp);
            }
            iter++;
            error = ((A*res) - b);
        }
        
        if (verbose)
        {
            std::cout << "Reached convergence in : " << iter << " iterations\n";
        }

        
        return res;


    }
};

#endif