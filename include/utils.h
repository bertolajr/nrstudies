#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>

static inline void dswap(double *a, double *b) 
/* Swap two double type variables. */
{
    double tmp = *a;
    *a = *b;
    *b = tmp;
}

void error(char *error_message);
/* The default error handler for the studies. */

int *ivector(size_t n);
/* Allocates an integer vector in the default format v[0,...,n-1]. */

void free_ivector(int *v);
/* Free an integer vector previously allocated with ivector. */

#endif /* UTILS_H */
