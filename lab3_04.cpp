/*
--Dynamic Array Analysis Using Pointer Arithmetic--

Write a C++ program that dynamically allocates an integer array using the new operator.

Your task is to perform multiple operations on the array using pointer arithmetic only.

You must read the array elements using pointers and access every element using pointer arithmetic instead of array indexing.

Your program should:

Read the size of the array N.
Dynamically allocate memory using the new operator.
Read N integers into the array using pointer arithmetic.
Calculate the sum of all elements. 5. Find the minimum element.
Find the maximum element.
Count the number of even elements.
Reverse the array in-place using two pointers.
Print all calculated results and the reversed array.
Release the allocated memory using delete[].
Important Rules:

You must access elements using pointer arithmetic.
Use *(ptr + i) instead of arr[i].
Do not use vector.
Do not create another array for reversing.
The reversal must be performed in-place using pointers only.
Input Format

The first line contains an integer N.

The second line contains N space-separated integers.

Constraints

1 <= N <= 100000

-10^9 <= *(ptr + i) <= 10^9

The answer for the sum will fit within a 64-bit signed integer.

Output Format

Print the results exactly in the following format: Sum: Minimum: Maximum: Even Count: Reversed Array:

Sample Input 0

6 
-5 12 0 9 -8 4
Sample Output 0

Sum: 12 
Minimum: -8 
Maximum: 12 
Even Count: 4 
Reversed Array: 4 -8 9 0 12 -5
Sample Input 1

5 
10 3 8 7 2
Sample Output 1

Sum: 30 
Minimum: 2 
Maximum: 10 
Even Count: 3 
Reversed Array: 2 7 8 3 10
Explanation 1

The dynamically allocated array contains: 10 3 8 7 2 Sum of all elements: 10 + 3 + 8 + 7 + 2 = 30 Minimum element = 2 Maximum element = 10 Even elements are: 10, 8, 2 Therefore Even Count = 3 After reversing the array in-place using two pointers: 2 7 8 3 10 All array accesses must be performed using pointer arithmetic.
*/

#include <iostream>
using namespace std;

int main() {
    
    int N;
    cin >> N;

    int* arr = new int[N];

    for (int i = 0; i < N; ++i) {
        cin >> *(arr + i);
    }


    int sum = 0;
    int min = *(arr + 0);
    int max = *(arr + 0);
    int count = 0;

    for (int i = 0; i < N; ++i) {
        int curr_val = *(arr + i);
        
        sum += curr_val;
        
        if (curr_val < min) {
            min = curr_val;
        }
        
        if (curr_val > max) {
            max = curr_val;
        }
        
        if (curr_val % 2 == 0) {
            count++;
        }
    }

    int* left = arr;
    int* right = arr + N - 1;
    
    while (left < right) {
        int temp = *left;
        *left = *right;
        *right = temp;
        left++;
        right--;
    }
    
    cout << "Sum: " << sum << "\n";
    cout << "Minimum: " << min << "\n";
    cout << "Maximum: " << max << "\n";
    cout << "Even Count: " << count << "\n";
    
    cout << "Reversed Array: ";
    for (int i = 0; i < N; ++i) {
        cout << *(arr + i) << (i == N - 1 ? "" : " ");
    }
    cout << "\n";

    delete[] arr;

    return 0;
}
