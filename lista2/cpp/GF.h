#ifndef GF_H
#define GF_H

#include <iostream>

const int PRIME_NUMBER = 1234577;

class GF {
private:
    int value;

public:
    GF(int value);

    int characteristic();

    bool operator ==(const GF& other);

    bool operator !=(const GF& other);

    bool operator <=(const GF& other);

    bool operator >=(const GF& other);

    bool operator <(const GF& other);

    bool operator >(const GF& other);

    void operator +=(const GF& other);

    void operator -=(const GF& other);

    void operator *=(const GF& other);

    void operator /=(const GF& other);

    friend GF operator +(const GF& l, const GF& r);

    friend GF operator -(const GF& l, const GF& r);

    friend GF operator *(const GF& l, const GF& r);

    friend GF operator /(const GF& l, const GF& r);

    friend std::ostream& operator <<(std::ostream& os, const GF& gf);

    friend std::istream& operator >>(std::istream& is, GF& gf);
};

#endif // GF_H
