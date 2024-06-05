// DHSetup.cpp

import java.util.Random;

class DHSetup {
    private final GF generator;

    public DHSetup() {
        Random random = new Random();
        long generatorValue;
        do {
            generatorValue = random.nextInt(GF.characteristic())+1;
        } while (!isGenerator(generatorValue));
        this.generator = new GF(generatorValue);
    }

    private boolean isGenerator(long candidate) {
        GF temp = new GF(candidate);
        for (long q = 2; q * q <= GF.characteristic() - 1; q++) {
            if (isPrime(q) && (GF.characteristic()-1) % q == 0 ) {
                long exp = (GF.characteristic() - 1) / q;
                GF result = power(temp, exp);
                GF one = new GF(1);
                if (result == one) {
                    return false;
                }
            }
        }
        return true;
    }

    private static boolean isPrime(long number) {
        if (number <= 1) {
            return false;
        }
        for (long i = 2; i <= Math.sqrt(number); i++) {
            if (number % i == 0) {
                return false;
            }
        }
        return true;
    }

    public GF getGenerator() {
        return generator;
    }

    public GF power(GF a, long b) {
        GF result = new GF(1);
        if (b == 0) {
            return result;
        }
        if (b == 1) {
            result = a;
            return result;
        }
        if (b % 2 == 0) {
            GF temp = power(a, b / 2);
            return GF.multiply(temp, temp);
        }
        if (b % 2 == 1) {
            GF temp = power(a, (b - 1) / 2);
            return GF.multiply(GF.multiply(temp, temp), a);
        }
        return result;
    }
}
