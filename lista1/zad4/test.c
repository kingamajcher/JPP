//test.c
#include "zad_4.h"
#include <stdio.h>

int main() {
    // testing functions for calculating factorial
    unsigned int n = 5;
    printf("loop:      %u! = %d\n", n, wrapped_factorial_l(n));
    printf("recursion: %u! = %d\n", n, wrapped_factorial_r(n));

    printf("-----------------------------------------------------------------\n");

    // testing functions for calculating greatest common divisor
    unsigned int a = 12, b = 18;
    printf("loop:      GCD(%u, %u) = %u\n", a, b, wrapped_gcd_l(a, b));
    printf("resursion: GCD(%u, %u) = %u\n", a, b, wrapped_gcd_r(a, b));

    printf("-----------------------------------------------------------------\n");

    // Testowanie funkcji rozwiązującej liniowe równanie diofantyczne
    int eq_a = 3, eq_b = 7, eq_c = 8;
    DiophantineSolution solutionL = wrapped_diophantine_eq_l(eq_a, eq_b, eq_c);
    DiophantineSolution solutionR = wrapped_diophantine_eg_r(eq_a, eq_b, eq_c);
    printf("loop:      Solution: %dx + %dy = %d:     x = %d + %dk, y = %d + %dk\n", eq_a, eq_b, eq_c, solutionL.x, solutionL.xk, solutionL.y, solutionL.yk);
    printf("recursion: Solution: %dx + %dy = %d:     x = %d + %dk, y = %d + %dk\n", eq_a, eq_b, eq_c, solutionR.x, solutionR.xk, solutionR.y, solutionR.yk);

    return 0;
}