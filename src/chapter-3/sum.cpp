#include <math.h> // fabs()
#include <stdlib.h> // malloc() and free() 
#include <stdio.h>
#define EPSILON 1.0e-14 // a small number
void sum(double *x, double *y, double *z, int N);
void check(double *z, int N);

int main(void) 
{
    int N = 1024 * 100000;
    int M = sizeof(double) * N;
    double *x = (double*) malloc(M);
    double *y = (double*) malloc(M);
    double *z = (double*) malloc(M);
    for (int n = 0; n < N; ++n)
    {
        x[n] = 1.0; y[n] = 2.0; z[n] = 0.0;
    }
    sum(x, y, z, N);
    check(z, N);
    free(x); free(y); free(z);
    return 0;
}

void sum(double *x, double *y, double *z, int N)
{
    for (int n = 0; n < N; ++n) { z[n] = x[n] + y[n]; }
}

void check(double *z, int N)
{
    int has_error = 0;
    for (int n = 0; n < N; ++n)
    {
        double diff = fabs(z[n] - 3.0);
        if (diff > EPSILON) { has_error = 1; }
    }
    if (has_error) { printf("Has errors.\n"); }
    else { printf("No errors.\n"); }
}
