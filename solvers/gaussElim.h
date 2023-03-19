#ifndef GAUSSELIM_H
#define GAUSSELIM_H

#include <iostream>
#include <math.h>
#include <vector>

#include "bMatrix.h"
#include "bVector.h"

template <typename T>
bVector<T> gaussEllim(const bMatrix<T> *A, const bVector<T> *b)
{
    // make a copy of the input matrix
    bMatrix<T> inputMatrix = *A;

    bMatrix<T> bMat(b->length(), 1, b->vectorData);

    inputMatrix.join(bMat);

    bMatrix<T> rowEchelonMatrix = inputMatrix.rowEchelon();

    bVector<T> output(b->vectorData);

    // now use back-substituion to compute the resuts

    int numRows = rowEchelonMatrix.getNumRows();
    int numCols = rowEchelonMatrix.getNumCols();
    int startRow = numRows - 1;

    for(int i = startRow; i>=0; i--)
    {
        T currentResult = rowEchelonMatrix.getElement(i, numCols-1);

        T cumSum = static_cast<T>(0.0);
        for (int j=i+1; j<numRows; j++)
        {
            cumSum += rowEchelonMatrix.getElement(i,j) * output.getElement(j);
        }
        T finalAnswer = (currentResult - cumSum) / rowEchelonMatrix.getElement(i,i);

        output.setElement(i, finalAnswer);
    }

    return output;
}

#endif