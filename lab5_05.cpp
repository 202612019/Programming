/*
--Implicit and Explicit Type Casting in C++--

Problem Statement
Write a C++ program to demonstrate implicit and explicit type casting.


You are given a floating-point value as input, stored in a variable of type double.


Perform the following operations:


1. Implicit Type Casting
Implicitly cast the double value to:
- int
- float


Print the results.


2. Explicit Type Casting
Explicitly cast the double value to:
- long long using C-style casting
- long long using static_cast
- char using C-style casting
- char using static_cast


Print the results.


Finally, explain the differences in the outputs and discuss the risk of data loss caused by these type conversions.

Input Format

A single line containing a floating-point number.
Constraints

Program must compile using a standard C++ compiler.
Output Format

Print the following values clearly with labels:

Original double value
Result after implicit casting to int
Result after implicit casting to float
Result after explicit casting to long long (C-style)
Result after explicit casting to long long (static_cast)
Result after explicit casting to char (C-style)
Result after explicit casting to char (static_cast)
Sample Input 0

65.0
Sample Output 0

Original double value: 65
Result after implicit casting to int: 65
Result after implicit casting to float: 65
Result after explicit casting to long long (C-style): 65
Result after explicit casting to long long (static_cast): 65
Result after explicit casting to char (C-style): A
Result after explicit casting to char (static_cast): A
Sample Input 1

100000000.5
Sample Output 1

Original double value: 1e+08
Result after implicit casting to int: 100000000
Result after implicit casting to float: 1e+08
Result after explicit casting to long long (C-style): 100000000
Result after explicit casting to long long (static_cast): 100000000
Result after explicit casting to char (C-style): 
Result after explicit casting to char (static_cast): 
*/

#include <iostream>
using namespace std;

int main() {
    
    double n;
    cin >> n;
    
    int i = n;
    float f = n;
    
    long long l = (long long)n;
    long long sl = static_cast<long long>(n);
    char c = (char)n;
    char sc = static_cast<char>(n);
    
    cout << "Original double value: " << n << "\n";
    
    cout << "Result after implicit casting to int: " << i <<endl;
    cout << "Result after implicit casting to float: " << f <<endl;
    
    cout << "Result after explicit casting to long long (C-style): " << l <<endl;
    cout << "Result after explicit casting to long long (static_cast): " << sl <<endl;
    
    cout << "Result after explicit casting to char (C-style): " << c <<endl;
    cout << "Result after explicit casting to char (static_cast): " << sc<<endl;
    
    return 0;
}