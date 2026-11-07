#ifndef UTILS_H
#define UTILS_H

static inline void dswap(double *a, double *b) 
/* Swap two double type variables. */
{
    double tmp = *a;
    *a = *b;
    *b = tmp;
}

#endif /* UTILS_H */