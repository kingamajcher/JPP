#include "GF.h"

GF::GF(int value) : value((value % PRIME_NUMBER + PRIME_NUMBER) % PRIME_NUMBER) {}

int GF::characteristic() {
    return PRIME_NUMBER;
}

bool GF::operator ==(const GF& other) {
    return value == other.value;
}

bool GF::operator !=(const GF& other) {
    return !(*this == other);
}

bool GF::operator <=(const GF& other) {
    return value <= other.value;
}

bool GF::operator >=(const GF& other) {
    return value >= other.value;
}

bool GF::operator <(const GF& other) {
    return value < other.value;
}

bool GF::operator >(const GF& other) {
    return value > other.value;
}

void GF::operator +=(const GF& other) {
    value = (value + other.value) % PRIME_NUMBER;
}

void GF::operator -=(const GF& other) {
    value = (value - other.value + PRIME_NUMBER) % PRIME_NUMBER;
}

void GF::operator *=(const GF& other) {
    value = (value * other.value) % PRIME_NUMBER;
}

void GF::operator /=(const GF& other) {
    if (other.value == 0)
        throw std::invalid_argument("Division by zero");
    int inv = 1;
    int base = other.value;
    int exponent = PRIME_NUMBER - 2;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            inv = (inv * base) % PRIME_NUMBER;
        }
        base = (base * base) % PRIME_NUMBER;
        exponent /= 2;
    }

    // Normalize the result to ensure it's positive
    if (inv < 0) {
        inv += PRIME_NUMBER;
    }

    // Perform the division
    value = (static_cast<long long>(value) * inv) % PRIME_NUMBER;
}

GF operator +(const GF& l, const GF& r) {
    GF result = l;
    result += r;
    return result;
}

GF operator -(const GF& l, const GF& r) {
    GF result = l;
    result -= r;
    return result;
}

GF operator *(const GF& l, const GF& r) {
    GF result = l;
    result *= r;
    return result;
}

GF operator /(const GF& l, const GF& r) {
    GF result = l;
    result /= r;
    return result;
}

std::ostream& operator <<(std::ostream& os, const GF& gf) {
    os << gf.value;
    return os;
}

std::istream& operator >>(std::istream& is, GF& gf) {
    int temp;
    is >> temp;
    gf = GF(temp);
    return is;
}
