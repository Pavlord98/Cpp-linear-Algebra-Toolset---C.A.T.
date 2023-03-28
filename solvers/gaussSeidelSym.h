#ifndef GAUSSSEIDELSYM_H
#define GAUSSSEIDELSYM_H

#include <iostream>
#include <math.h>
#include <vector>

#include "bMatrix.h"
#include "bVector.h"

template <typename T>
bMatrix<T> gaussSeidelSym( const bMatrix<T>& A, const bMatrix<T>& b, double alpha = 1, double tolerance = 1e-4, int maxIters=10000, bool verbose = true )
{
    
    if ( !A.isDiagDom() || !A.isSym() || !A.isPositive() )
        throw "Incompatible matrix input! Matrix must be diagonally dominant, symetric and positive!";
    
   
    // Initialize an empty result vector;
    bMatrix<T> res(A.getNumRows(),1); // should add suport for non zero initialization

    T temp, tempSum;
    
    bMatrix<T> error(A.getNumRows(),1,"ones");
    int iter = 0;

    while( error.L2Norm() >= tolerance && iter <= maxIters)
    {
        int forwardCount  = 0;
        int backWardCount = A.getNumRows() -1 ;
        for (int i = 0; i < A.getNumRows(); i++)
        {
            if (i&2 == 0)
            {
                tempSum = 0;
                temp = 0;
                for(int j = 0; j < A.getNumCols(); j++)
                {
                    if (forwardCount != j)
                        tempSum += A.getElement(forwardCount,j)*res.getElement(j);
                }
                
                temp = (1-alpha)*res.getElement(forwardCount) + alpha/A.getElement(forwardCount, forwardCount) * (b.getElement(forwardCount) - tempSum);
                res.setElement(forwardCount, 0, temp);
                forwardCount++;
            }
            else
            {
                tempSum = 0;
                temp = 0;
                for(int j = 0; j < A.getNumCols(); j++)
                {
                    if (backWardCount != j)
                        tempSum += A.getElement(backWardCount,j)*res.getElement(j);
                }
                
                temp = (1-alpha)*res.getElement(backWardCount) + alpha/A.getElement(backWardCount,backWardCount) * (b.getElement(backWardCount) - tempSum);
                res.setElement(backWardCount, 0, temp);
                backWardCount--;
            }
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


#endif