/*
--Default Argument and Inline Function--

Write an inline function calculatePower() to calculate the power of a number.

The function should have the following declaration:

inline int calculatePower(int base, int exponent = 2);

If the exponent is not provided, the default value 2 must be used.

Do not use the built-in pow() function.

The function should calculate base raised to the power exponent.

For example:

calculatePower(5) returns 25. calculatePower(5, 3) returns 125.

Input Format

The first line contains an integer base.

The second line contains an integer exponent.

Constraints

1 <= base <= 10 2 <= exponent <= 6

Output Format

Print the result in the following format:

Result:

Sample Input 0

5
3
Sample Output 0

Result: 125
Sample Input 1

2
4
Sample Output 1

Result: 16
*/

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
