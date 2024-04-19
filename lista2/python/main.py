from GF import GF

def main():
    a = GF(70)
    b = GF(1234588)
    c = GF(-30)
    result = GF()

    print("characteristic:", result.characteristic())

    print("a =", a)
    print("b =", b)
    print("c =", c)

    print("b inversed =", b.inverse())

    result = a + b
    print("a + b =", result)

    result = a - b
    print("a - b =", result)

    result = a * b
    print("a * b =", result)

    result = a / b
    print("a / b =", result)

    print("Is a == b?", a == b)
    print("Is a != b?", a != b)
    print("Is a < b?", a < b)
    print("Is a > b?", a > b)

if __name__ == "__main__":
    main()
