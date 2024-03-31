//c_lib.h
#ifndef C_LIB_H
#define C_LIB_H

#include <stdio.h>

typedef struct {
    int x;
    int y;
    int xk;
    int yk;
} DiophantineSolution;

unsigned long long factorialL(unsigned int n);

unsigned long long factorialR(unsigned int n);

unsigned int gcdL(unsigned int a, unsigned int b);

unsigned int gcdR(unsigned int a, unsigned int b);

static unsigned int gcdExtended(unsigned int a, unsigned int b, int *x, int *y);

static void diophantineFormat(int *x, int *y, int *xk, int *yk);

DiophantineSolution diophantineEqL(int a, int b, int c);

DiophantineSolution diophantineEqR(int a, int b, int c);

#endif