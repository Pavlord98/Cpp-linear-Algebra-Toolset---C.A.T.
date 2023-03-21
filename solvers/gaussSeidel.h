#ifndef GAUSSSEIDEL_H
#define GAUSSSEIDEL_H

#include <iostream>
#include <math.h>
#include <vector>

#include "bMatrix.h"
#include "bVector.h"

template <typename T>
bMatrix<T> gaussSeidel( bMatrix<T>& A,  bMatrix<T>& b, double tolerance = 1e-4, int maxIters=10000 )
{
    
    if ( !A.isDiagDom() || !A.isSym() || !A.isPositive() )
        throw "Incompatible matrix input! Matrix must be diagonally dominant, symetric and positive!";
    
   
    // Initialize an empty result vector;
    bMatrix<T> res(A.getNumRows(),1); // should add suport for non zero initialization

    T temp, tempSum;
    
    bMatrix<T> error(A.getNumRows(),1,"ones");
    int iter = 0;

    while( error.maxElement() >= tolerance && iter <= maxIters)
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
            
            temp = 1/A.getElement(i,i) * (b.getElement(i) - tempSum);
            res.setElement(i, 0, temp);
        }
        iter++;
        error = ((A*res) - b);
    }
    
    return res;


}


#endif