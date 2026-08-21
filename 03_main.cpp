#include <iostream>
#include "03_math.h"

int main() {
    int num = 11;
    std::cout << "Factorial of " << num << " is " << MathUtils::factorial(num) << std::endl;
    std::cout << "Is " << num << " prime? " << (MathUtils::isPrime(num) ? "Yes" : "No") << std::endl;
    return 0;
}