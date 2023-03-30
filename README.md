# Cpp (linear) Algebra Toolset -- C.A.T.

<p align="center">
  <img src="https://user-images.githubusercontent.com/84512701/228799226-e5f098f8-0922-4c2a-bdb9-336a649074d9.png"/>
</p>
This is a project of mine in which I am developing my own linear algebra library for personal use and practice.

## Current Features

* A templated matrix class for different data types 
* Support for the basic matrix operations via overloaded operators " (), +, -, *, = "
* Many methods for getting information regarding created matrices
* Support for initilazing Identity, Ones and Zeros matrices of any size
* Matrix inversion by the Gauss-Jordan method
* Joining and splitting matrices
* Calculate determinant
* Solving linear systems with the Gauss Elimination method
* Gauss-Seidel method for solving linear systems with under-relaxation
* Symmetric Gaus-Seidel solver
* compute norms (L1, L2 and Linf)

## Features currently in development

* Advanced indexing and slicing of matrices
* Matrix version of the Gauss-Seidel solver

## Upcoming features

* Conjugate and MultiGrid solvers
* QR decomposition
* Doxygen documentation

## Known buggs
* << overload does something weird, print() method works fine
