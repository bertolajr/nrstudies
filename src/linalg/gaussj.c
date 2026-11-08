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
    double pivinv, dum;
    /* pivinv: pivot inverse. this obviously stores the inverse value of the pivot */

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
        /* this checks if the pivot is located in the principal diagonal. if not, these loops interchange the rows to put the pivot in the principal diagonal */
            for (int l = 0; l < n; l++) dswap(&a[irow][l], &a[icol][l]);
            for (int l = 0; l < m; l++) dswap(&b[irow][l], &b[icol][l]);
        }
        /* this is for unscramble the matrix later */
        indxr[i]=irow;
        indxc[i]=icol;
        /* checks if the matrix is singular */
        if(a[icol][icol] == 0) error("gaussj: singular matrix.");

        /* now that the pivot is in place (a[icol][icol]) we can define the inverse value of the pivot, the pivinv */
        pivinv = 1.0/a[icol][icol];

        /* and then, instead of computing pivot/pivot, we just turn the pivot into 1. this is a good technique to minimize roundoff error */
        a[icol][icol] = 1;

        /* here we multiply the entire row by pivinv */
        for(int l = 0; l < n; l++) a[icol][l] *= pivinv;
        for(int l = 0; l < m; l++) b[icol][l] *= pivinv;

        /* now is when you reduce the columns to zeros */
        for(int ll = 0; ll < n; ll++) {
            if(ll != icol) {
                dum = a[ll][icol];
                a[ll][icol] = 0.0;
                for(int l = 0; l < n; l++) a[ll][l] -= a[icol][l] * dum;
                for(int l = 0; l < m; l++) b[ll][l] -= b[icol][l] * dum;
            }
        }
    }
    /* I know this part serves for unscramble the column changes in the matrix. but I just can't understand the mechanism */
    for(int l = n - 1; l >= 0; l--) {
        if(indxr[l] != indxc[l]) {
            for (int k = 0; k < n; k++) dswap(&a[k][indxr[l]], &a[k][indxc[l]]);
        }
    }
    free_ivector(ipiv);
    free_ivector(indxr);
    free_ivector(indxc);
}
