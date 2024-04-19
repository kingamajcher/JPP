#include <iostream>
#include "GF.h"

int main() {
    GF a(70);
    GF b(1234588);
    GF c(-30);
    GF result(0);

    std::cout << "characteristic: " << result.characteristic() << std::endl;

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "c = " << c << std::endl;

    std::cout << "b inversed = " << b.inverse() << std::endl;

    result = a + b;
    std::cout << "a + b = " << result << std::endl;

    result = a - b;
    std::cout << "a - b = " << result << std::endl;

    result = a * b;
    std::cout << "a * b = " << result << std::endl;

    result = a / b;
    std::cout << "a / b = " << result << std::endl;

    std::cout << "Is a == b? " << std::boolalpha << (a == b) << std::endl;
    std::cout << "Is a != b? " << std::boolalpha << (a != b) << std::endl;
    std::cout << "Is a < b? " << std::boolalpha << (a < b) << std::endl;
    std::cout << "Is a > b? " << std::boolalpha << (a > b) << std::endl;

    return 0;
}
