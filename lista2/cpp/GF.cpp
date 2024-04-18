#include <iostream>

template <int p>
class GF{
    private:
        int value;
    public:
        GF(int value) : value((value % p + p) % p) {}

        int characteristic() {
            return p;
        }
        bool operator ==(const GF& other) {
            return value == other.value;
        }
        bool operator !=(const GF& other) {
            return !(*this == other);
        }
        bool operator <=(const GF& other) {
            return value <= other.value;
        }
        bool operator >=(const GF& other) {
            return value >= other.value;
        }
        bool operator <(const GF& other) {
            return value < other.value;
        }
        bool operator >(const GF& other) {
            return value > other.value;
        }
        void operator +=(const GF& other) {
            value = (value + other.value) % p;
        }
        void operator -=(const GF& other) {
            value = (value - other.value + p) % p;
        }
        void operator *=(const GF& other) {
            value = (value * other.value) % p;
        }
        void operator /=(const GF& other) {
            if (other.value == 0)
                throw std::invalid_argument("Division by zero");
            int inv = 1;
            int base = other.value;
            int exponent = p - 2;
            while (exponent > 0) {
                if (exponent % 2 == 1) {
                    inv = (inv * base) % p;
                }
                base = (base * base) % p;
                exponent /= 2;
            }

            // Normalize the result to ensure it's positive
            if (inv < 0) {
                inv += p;
            }

            // Perform the division
            value = (static_cast<long long>(value) * inv) % p;
        }
        friend GF operator +(const GF& l, const GF& r) {
            GF result = l;
            result += r;
            return result;
        }
        friend GF operator -(const GF& l, const GF& r) {
            GF result = l;
            result -= r;
            return result;
        }
        friend GF operator *(const GF& l, const GF& r) {
            GF result = l;
            result *= r;
            return result;
        }
        friend GF operator /(const GF& l, const GF& r) {
            GF result = l;
            result /= r;
            return result;
        }
        friend std::ostream& operator <<(std::ostream& os, const GF& gf) {
            os << gf.value;
            return os;
        }
        friend std::istream& operator >>(std::istream& is, GF& gf) {
            int temp;
            is >> temp;
            gf = GF(temp);
            return is;
        }
};