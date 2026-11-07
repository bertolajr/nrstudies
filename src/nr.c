#include <stdio.h>
#include "utils.h"

int main(void) {
    double x = 5.1;
    double y = 7.5;

    printf("Original values: %lf, %lf\n", x, y);
    dswap(&x, &y);

    printf("Swapped values: %lf, %lf\n", x, y);

    return 0;
}