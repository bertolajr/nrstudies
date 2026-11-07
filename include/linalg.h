#ifndef LINALG_H
#define LINALG_H

void gaussj(double **a, int n, double **b, int m);
/*
Computes the solutions x_{i} of a matrix equation Ax_{i}=b_{i}, given a fixed coefficient matrix A (a) and the righ-hand side matrices b_{i}. Also computes the inverse matrix of A.

When the algorithm is finished, the input b becomes the solution matrix x, and the input a becomes the inverse matrix of A.
*/

#endif /* LINALG_H */
