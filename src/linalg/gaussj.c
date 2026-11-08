#include <math.h>
#include "utils.h"
#include "linalg.h"

void gaussj(double **a, int n, double **b, int m) {
    int *indxc = ivector(n);
    int *indxr = ivector(n);
    int *ipiv = ivector(n);

    int icol, irow;
    double biggest;

    for(int i = 0; i < n; i++) { // loop do pivoteamento
        biggest = 0.0;
        for(int j = 0; j < n; j++) { // loop da linha
            if(ipiv[j] != 1) {
                for(int k = 0; k < n; k++) { // loop da coluna
                    if(ipiv[k] == 0) { 
                        if(fabs(a[j][k]) >= biggest) { 
                            biggest = fabs(a[j][k]);
                            irow = j;
                            icol = k;
                        }
                    }
                }
            }
        }
        ++(ipiv[icol]);
    }
}
