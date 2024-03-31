// test.c
#include "c_lib.h"
#include <stdio.h>

int main() {
    // testing functions for calculating factorial
    unsigned int n = 5;
    printf("loop:      %u! = %llu\n", n, factorialL(n));
    printf("recursion: %u! = %llu\n", n, factorialR(n));

    // testing functions for calculating greatest common divisor
    unsigned int a = 12, b = 18;
    printf("loop:      GCD(%u, %u) = %u\n", a, b, gcdL(a, b));
    printf("resursion: GCD(%u, %u) = %u\n", a, b, gcdR(a, b));

    // Testowanie funkcji rozwiązującej liniowe równanie diofantyczne
    int eq_a = 3, eq_b = 7, eq_c = 8;
    DiophantineSolution solutionL = diophantineEqL(eq_a, eq_b, eq_c);
    DiophantineSolution solutionR = diophantineEqR(eq_a, eq_b, eq_c);
    printf("loop:      Solution: %dx + %dy = %d:     x = %d + %dk, y = %d + %dk\n", eq_a, eq_b, eq_c, solutionL.x, solutionL.xk, solutionL.y, solutionL.yk);
    printf("recursion: Solution: %dx + %dy = %d:     x = %d + %dk, y = %d + %dk\n", eq_a, eq_b, eq_c, solutionR.x, solutionR.xk, solutionR.y, solutionR.yk);
    
    return 0;
}