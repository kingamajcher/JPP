// test.c
#include "zad_7.h"
#include <stdio.h>

int main() {
    // testing functions for calculating factorial
    unsigned int n = 5;
    printf("loop:      %u! = %llu\n", n, wrapped_factorialL(n));
    printf("recursion: %u! = %llu\n", n, wrapped_factorialR(n));

    printf("-----------------------------------------------------------------\n");

    // testing functions for calculating greatest common divisor
    unsigned int a = 12, b = 18;
    printf("loop:      GCD(%u, %u) = %u\n", a, b, wrapped_gcdL(a, b));
    printf("resursion: GCD(%u, %u) = %u\n", a, b, wrapped_gcdR(a, b));

    printf("-----------------------------------------------------------------\n");

    // Testowanie funkcji rozwiązującej liniowe równanie diofantyczne
    int eq_a = 3, eq_b = 7, eq_c = 8;
    DiophantineSolution solutionL = wrapped_diophantineL(eq_a, eq_b, eq_c);
    DiophantineSolution solutionR = wrapped_diophantineR(eq_a, eq_b, eq_c);
    printf("loop:      Solution: %dx + %dy = %d:     x = %d + %dk, y = %d + %dk\n", eq_a, eq_b, eq_c, solutionL.x, solutionL.xk, solutionL.y, solutionL.yk);
    printf("recursion: Solution: %dx + %dy = %d:     x = %d + %dk, y = %d + %dk\n", eq_a, eq_b, eq_c, solutionR.x, solutionR.xk, solutionR.y, solutionR.yk);
    
    return 0;
}