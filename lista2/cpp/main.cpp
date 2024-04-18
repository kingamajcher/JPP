#include <iostream>
#include "GF.cpp"

int main() {
    GF<79> a(70);
    GF<79> b(3);
    GF<79> c(-30);
    GF<79> result(0);

    std::cout << "characteristic: " << result.characteristic() << std::endl;

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "c = " << c << std::endl;

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

}