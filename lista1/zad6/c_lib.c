// c_lib.c
#include "c_lib.h"
#include <stdio.h>
#include <stdlib.h>

unsigned long long factorialL(unsigned int n) {
    unsigned long long result = 1;

    for (unsigned int i = 1; i <= n; i++) {
        result = result * i;
    }
    return result;
}

unsigned long long factorialR(unsigned int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    else {
        return n * factorialR(n-1);
    }
}

unsigned int gcdL(unsigned int a, unsigned int b) {
    while (b != 0) {
        unsigned int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

unsigned int gcdR(unsigned int a, unsigned int b) {
    if (b == 0) {
        return a;
    }
    else {
        return gcdR(b, a % b);
    }
}

static unsigned int gcdExtended(unsigned int a, unsigned int b, int *x, int *y) {
    if (a == 0) {
        *x = 0;
        *y = 1;
        return b;
    }

    int x0, y0;
    int gcd = gcdExtended(b % a, a, &x0, &y0);

    *x = y0 - (b/a) * x0;
    *y = x0;

    return gcd;
}

static void diophantineFormat(int *x, int *y, int *xk, int *yk) {
    int n = 0;
    while (*x > 0) {
        *x = *x - *xk;
        n--;
    }
    while (*x < 0) {
        *x = *x + *xk;
        n++;
    }
    *y = *y + n*(*yk);
}

DiophantineSolution diophantineEqL(int a, int b, int c) {
    DiophantineSolution solution;
    solution.x = 0;
    solution.y = 0;
    solution.xk = 0;
    solution.yk = 0;

    // checking whether solution exist using Bezout's identity, if not then returning x = 0 and y = 0
    int gcd = gcdL(abs(a), abs(b));
    if (c % gcd != 0) {
        solution.x = 0;
        solution.y = 0;
        solution.xk = 0;
        solution.yk = 0;
        return solution;
    }

    while (solution.x < abs(b / gcd)) {
        if ((c - a * solution.x) % b == 0) {
            solution.y = (c - a * solution.x) / b;
            break;
        }
        solution.x++;
    }

    if (a < 0) {
        solution.x = -solution.x;
    }
    if (b < 0) {
        solution.y = -solution.y;
    }

    solution.xk = b / gcd;
    solution.yk = - a / gcd;

    diophantineFormat(&solution.x, &solution.y, &solution.xk, &solution.yk);

    return solution;
}


DiophantineSolution diophantineEqR(int a, int b, int c) {
    DiophantineSolution solution;

    // checking whether solution exist using Bezout's identity, if not then returning x = 0 and y = 0
    int gcd = gcdExtended(abs(a), abs(b), &solution.x, &solution.y);
    if (c % gcd != 0) {
        solution.x = 0;
        solution.y = 0;
        solution.xk = 0;
        solution.yk = 0;
        return solution;
    }
    
    solution.x = solution.x * (c / gcd);
    solution.y = solution.y * (c /gcd);

    if (a < 0) {
        solution.x = -solution.x;
    }
    if (b < 0) {
        solution.y = -solution.y;
    }

    solution.xk = b / gcd;
    solution.yk = - a / gcd;

    diophantineFormat(&solution.x, &solution.y, &solution.xk, &solution.yk);

    return solution;
}