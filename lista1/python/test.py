# test.py
from python_lib import *

# Testing functions for calculating factorial
n = 5
print("loop:      {}! = {}".format(n, factorialL(n)))
print("recursion: {}! = {}".format(n, factorialR(n)))

# Testing functions for calculating greatest common divisor
a, b = 12, 18
print("loop:      GCD({}, {}) = {}".format(a, b, gcdL(a, b)))
print("recursion: GCD({}, {}) = {}".format(a, b, gcdR(a, b)))

# Testing functions for solving linear diophantine equation
eq_a, eq_b, eq_c = 3, 7, 8
solutionL = diophantineEqL(eq_a, eq_b, eq_c)
solutionR = diophantineEqR(eq_a, eq_b, eq_c)
print("loop:      Solution: {}x + {}y = {}:     x = {} + {}k, y = {} + {}k".format(eq_a, eq_b, eq_c, solutionL[0], solutionL[2], solutionL[1], solutionL[3]))
print("recursion: Solution: {}x + {}y = {}:     x = {} + {}k, y = {} + {}k".format(eq_a, eq_b, eq_c, solutionR[0], solutionR[2], solutionR[1], solutionR[3]))