/*
--Count the Number of Digit 1s--

Given a non-negative integer n, count the total number of times the digit 1 appears in all non-negative integers from 0 to n, inclusive.

For example, if n = 13, the numbers from 0 to 13 are:

0, 1, 2, ..., 10, 11, 12, 13

The digit 1 appears:

Once in 1
Twice in 11
Once in 10
Once in 12
Once in 13
Therefore, the total count is 6.

Your task is to write an efficient program using "RECURSION" only that calculates this count. If found that the you used iterateve method than you will be graded zero for this Problem

Input Format

A single integer n

Constraints

0 <= n <= 10^9
The solution should handle large values of n efficiently.
Output Format

Print a single integer representing the total number of times the digit 1 appears in all integers from 0 to n, inclusive.

Sample Input 0

13
Sample Output 0

6
*/

#include <iostream>
using namespace std;

int get_base(int n, int base) {
    if (n < 10) {
        return base;
    }
    return get_base(n / 10, base * 10);
}

int  countDigitOne(int n) {
    if (n <= 0) return 0;
    if (n < 10) return 1;

    int base = get_base(n, 1);
    int  m = n / base;
    int r = n % base;

    int o_base = countDigitOne(base - 1);
    
    if (m == 1) {
        return o_base + (r + 1) + countDigitOne(r);
    } 
    else {
        return m * o_base + base + countDigitOne(r);
    }
}

int main() {
    

    int n;
    cin >> n;
    cout << countDigitOne(n) << "\n";

    return 0;
}
