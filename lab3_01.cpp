#include <cmath>
#include <iostream>
using namespace std;

inline int calculatePower(int base, int exponent = 2) {
    return (pow(base, exponent));
}

int main() {
    int base, exponent;
    cin >> base >> exponent;

    cout << "Result: " <<calculatePower(base, exponent);

    return 0;
}
