#ifndef VECADD_H_
#define VECADD_H_

#include "stdio.h"


void add_vectorized(double *__restrict__ a, double *__restrict__ b, double *__restrict__ c);
void add_nonvectorized(double *a, double *b, double *c);

void multiply_vectorized(double *__restrict__ a, double *__restrict__ b, double *__restrict__ c);
void multiply_nonvectorized(double *a, double *b, double *c);

void divide_vectorized(double *__restrict__ a, double *__restrict__ b, double *__restrict__ c);
void divide_nonvectorized(double *a, double *b, double *c);


#endif