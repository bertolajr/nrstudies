#include <math.h>
#include "utils.h"
#include "linalg.h"

void gaussj(double **a, int n, double **b, int m) {
    int *indxc = ivector(n);
    int *indxr = ivector(n);
    int *ipiv = ivector(n);
    /* these vectors are tracking vectors. ipiv is for tracking already pivoted rows and columns, indxc and indxr are for tracking swapped rows and columns */

    int icol, irow;
    /* these variables stores the coordinates of the actual pivot */
    double biggest;
    /* and this variable stores the value (in magnitude) of the pivot */

    for(int i = 0; i < n; i++) {
    /* main loop for each pivoting */
    
        biggest = 0.0;
        for(int j = 0; j < n; j++) {
        /* start of the search for a pivot. this is the loop for the rows */
            if(ipiv[j] != 1) {
                for(int k = 0; k < n; k++) {
                /* and this is the loop for the columns */
                    if(ipiv[k] == 0) { 
                        if(fabs(a[j][k]) >= biggest) { 
                            biggest = fabs(a[j][k]);
                            irow = j;
                            icol = k;
                            /* now the magnitude of the pivot is stored in biggest. also the coordinates of the pivot are stored in irow and icol. */
                        }
                    }
                }
            }
        }
        ++(ipiv[icol]);
        /* ipiv is a tracking vector. it is filled with 0's. when a pivot is found, it changes its corresponding column index to 1, so that in the next pivoting loop we do not search for a pivot in a row and column already pivoted */

        if (irow != icol) { 
            for (int l = 0; l < n; l++) dswap(&a[irow][l], &a[icol][l]);
            for (int l = 0; l < n; l++) dswap(&b[irow][l], &b[icol][l]);
        }
    }
}
