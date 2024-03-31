//zad_4.h
#ifndef ZAD_4_H
#define ZAD_4_H

typedef struct {
    int x;
    int y;
    int xk;
    int yk;
} DiophantineSolution;

extern int Factorial_L(int N);
extern int Factorial_R(int N);
extern int GCD_L(int A, int B);
extern int GCD_R(int A, int B);
extern DiophantineSolution Diophantine_Eq_L(int A, int B, int C);
extern DiophantineSolution Diophantine_Eq_R(int A, int B, int C);

int wrapped_factorial_l(int n);
int wrapped_factorial_r(int n);
int wrapped_gcd_l(int a, int b);
int wrapped_gcd_r(int a, int b);
DiophantineSolution wrapped_diophantine_eq_l(int a, int b, int c);
DiophantineSolution wrapped_diophantine_eg_r(int a, int b, int c);

#endif