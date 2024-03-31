//c_lib.h
#ifndef C_LIB_H
#define C_LIB_H

#include <stdio.h>

// struct for solution of diofantic equation
typedef struct {
    int x;
    int y;
    int xk;
    int yk;
} DiophantineSolution;

// function calculating factorial of n using loop
unsigned long long factorialL(unsigned int n);

// function calculating factorial of n using recursion
unsigned long long factorialR(unsigned int n);

// function calculating greatest common divider of a and b using loop
unsigned int gcdL(unsigned int a, unsigned int b);

// function calculating greatest common divider of a and b using recursion
unsigned int gcdR(unsigned int a, unsigned int b);

// function to help calculate solutions to diophantine equation
static unsigned int gcdExtended(unsigned int a, unsigned int b, int *x, int *y);

// function to format the solution of diophantine equation
static void diophantineFormat(int *x, int *y, int *xk, int *yk);

// function to calculate the solution of Diophantine equation using loop
DiophantineSolution diophantineEqL(int a, int b, int c);

// function to calculate the solution of Diophantine equation using recursion
DiophantineSolution diophantineEqR(int a, int b, int c);

#endif