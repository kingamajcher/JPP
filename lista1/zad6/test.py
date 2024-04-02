# test.py
from zad_6 import factorialL, factorialR, gcdL, gcdR, diophantineEqL, diophantineEqR

# Testing functions for calculating factorial
n = 5
print("loop:      {}! = {}".format(n, factorialL(n)))
print("recursion: {}! = {}".format(n, factorialR(n)))

print("-----------------------------------------------------------------")

# Testing functions for calculating greatest common divisor
a, b = 12, 18
print("loop:      GCD({}, {}) = {}".format(a, b, gcdL(a, b)))
print("recursion: GCD({}, {}) = {}".format(a, b, gcdR(a, b)))

print("-----------------------------------------------------------------")

# Testing functions for solving linear diophantine equation
eq_a, eq_b, eq_c = 3, 7, 8
solutionL = diophantineEqL(eq_a, eq_b, eq_c)
solutionR = diophantineEqR(eq_a, eq_b, eq_c)
print("loop:      Solution: {}x + {}y = {}:     x = {} + {}k, y = {} + {}k".format(eq_a, eq_b, eq_c, solutionL.x, solutionL.xk, solutionL.y, solutionL.yk))
print("recursion: Solution: {}x + {}y = {}:     x = {} + {}k, y = {} + {}k".format(eq_a, eq_b, eq_c, solutionR.x, solutionR.xk, solutionR.y, solutionR.yk))