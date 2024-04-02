# python_lib.py

# function calculating factorial of n using loop
def factorialL(n):
    result = 1
    for i in range (1, n+1):
        result = result * i
    return result

# function calculating factorial of n using recursion
def factorialR(n):
    if n == 0 or n == 1:
        return 1
    else:
        return n * factorialR(n-1)
    
# function calculating greatest common divider of a and b using loop
def gcdL(a, b):
    while b != 0:
        temp = b
        b = a % b
        a = temp
    return a

# function calculating greatest common divider of a and b using recursion
def gcdR(a, b):
    if b == 0:
        return a
    else:
        return gcdR(b, a % b)
    
# function to help calculate solutions to diophantine equation
def _gcdExtended(a, b):
    if a == 0:
        return b, 0, 1

    gcd, x0, y0 = _gcdExtended(b % a, a)

    x = y0 - (b // a) * x0
    y = x0

    return gcd, x, y

# function to format the solution of diophantine equation
def _diophantineFormat(x, y, xk, yk):
    n = 0
    while x > 0:
        x = x - xk
        n = n - 1
    while x < 0:
        x = x + xk
        n = n + 1
    y = y + n*yk
    return x, y, xk, yk

# function to calculate the solution of Diophantine equation using loop
def diophantineEqL(a, b, c):
    x = 0
    y = 0
    xk = 0
    yk = 0

    # checking whether solution exist using Bezout's identity, if not then returning x = 0 and y = 0
    gcd = gcdL(abs(a), abs(b))
    if c % gcd != 0:
        x = 0
        y = 0
        xk = 0
        yk = 0
        return x, y, xk, yk
    
    while x < abs(b / gcd):
        if (c - a * x) % b == 0:
            y = (c - a * x) / b
            break
        x = x + 1

    if a < 0:
        x = -x
    if b < 0:
        y = -y

    xk = b / gcd
    yk = - a / gcd

    x, y, xk, yk = _diophantineFormat(x, y, xk, yk)

    return x, y, xk, yk

# function to calculate the solution of Diophantine equation using recursion
def diophantineEqR(a, b, c):
    # checking whether solution exist using Bezout's identity, if not then returning x = 0 and y = 0
    gcd, x, y = _gcdExtended(abs(a), abs(b))
    if c % gcd != 0:
        x = 0
        y = 0
        xk = 0
        yk = 0
        return x, y, xk, yk
    
    x = x * (c / gcd)
    y = y * (c / gcd)

    if a < 0:
        x = -x
    if b < 0:
        y = -y

    xk = b / gcd
    yk = - a / gcd

    x, y, xk, yk = _diophantineFormat(x, y, xk, yk)

    return x, y, xk, yk