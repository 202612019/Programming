/*
--Longest Consecutive Sequence in an Array--

Given an array nums containing N integers, find and return the length of the longest sequence of consecutive integers.

The integers in the sequence can appear in any order in the original array.

A sequence of consecutive integers contains numbers where each number is exactly 1 greater than the previous number.

For example, the sequence [1, 2, 3, 4] has a length of 4.

Duplicate values in the array should not increase the length of a consecutive sequence.

Example 1:

Input

6

100 4 200 1 3 2

Output

4

Explanation: The longest consecutive sequence is [1, 2, 3, 4], which has a length of 4.

Example 2

Input

10

0 3 7 2 5 8 4 6 0 1

Output

9

Explanation: The longest consecutive sequence is [0, 1, 2, 3, 4, 5, 6, 7, 8], which has a length of 9

Input Format

The first line contains an integer N, representing the number of elements in the array.
The second line contains N space-separated integers representing the elements of the array.
Constraints

1 <= N <= 10^5
-10^9 <= nums[i] <= 10^9
Output Format

Print a single integer representing the length of the longest consecutive sequence in the array.

Sample Input 0

6
100 4 200 1 3 2
Sample Output 0

4
*/

#include <iostream>
#include <algorithm>
using namespace std;

int countSeqLength(int arr[],int n){
    int count = 1;
    sort(arr,arr+n);
    for(int i = 0; i < n-1;i++){
        if((arr[i+1]-arr[i]) >1){
            break;
        }
        if(arr[i+1] == arr[i]){
            continue;
        }
        if(arr[i+1] == arr[i]+1){
            count++;
        }
    }
    return count;
}

int main() {
    int n;
    cin>>n; 

    int arr[n];

    for(int i = 0; i<n;i++){ 
        cin>>arr[i];  
    }

    cout<<countSeqLength(arr, n);
    
    return 0;
}