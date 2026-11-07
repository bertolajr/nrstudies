#include <stdlib.h>
#include <stdio.h>
#include "utils.h"

void error(char *error_message) {
    fprintf(stderr, "Run-time error: %s\n", error_message);
    exit(EXIT_FAILURE);
}

int *ivector(size_t n) {
    int *v = calloc(n, sizeof(*v));
    if (!v) error("allocation failure in ivector()");
    return v;
}

void free_ivector(int *v) {
    free(v);
}
