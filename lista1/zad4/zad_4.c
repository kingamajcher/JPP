//zad_4.c
#include "zad_4.h"

int wrapped_factorial_l(int N) {
    return Factorial_R(N);
}

int wrapped_factorial_r(int N) {
    return Factorial_R(N);
}

int wrapped_gcd_l(int A, int B) {
    return GCD_L(A, B);
}

int wrapped_gcd_r(int A,int B) {
    return GCD_R(A, B);
}

DiophantineSolution wrapped_diophantine_eq_l(int A, int B, int C) {
    return Diophantine_Eq_L(A, B, C);
}

DiophantineSolution wrapped_diophantine_eg_r(int A, int B, int C) {
    return Diophantine_Eq_R(A, B, C);
}