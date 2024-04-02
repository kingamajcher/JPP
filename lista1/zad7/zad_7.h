//zad_7.h
#ifndef ZADANIE_7_H
#define ZADANIE_7_H

typedef struct {
    int x;
    int xk;
    int y;
    int yk;
} DiophantineSolution;

long long wrapped_factorialL(unsigned n);
long long wrapped_factorialR(unsigned n);
unsigned wrapped_gcdL(unsigned a, unsigned b);
unsigned wrapped_gcdR(unsigned a, unsigned b);
DiophantineSolution wrapped_diophantineL(int a, int b, int c);
DiophantineSolution wrapped_diophantineR(int a, int b, int c);

#endif // ZADANIE_7_H
