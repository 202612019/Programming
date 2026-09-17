/*
--Count Inversions--

Given an integer array nums, find and return the number of inversions in the array.

Two elements nums[i] and nums[j] form an inversion if:

i < j
nums[i] > nums[j]
An inversion represents a pair of elements that are in the wrong relative order.

For example, in the array [2, 3, 7, 1, 3, 5], the pairs (2,1), (3,1), (7,1), (7,3), and (7,5) form inversions. Therefore, the total number of inversions is 5.

A sorted array has an inversion count of 0.

Input Format

The first line contains an integer N, representing the number of elements in the array.
The second line contains N space-separated integers representing the elements of the array.
Constraints

1 <= N <= 10^5
-10^5 <= nums[i] <= 10^5
Output Format

Print a single integer representing the total number of inversions in the given array.

Sample Input 0

6
2 3 7 1 3 5
Sample Output 0

5
*/

#include <iostream>
using namespace std;

int countInversion(int arr[],int n){
    int count = 0;
    for(int i = 0; i < n-1;i++){
        for(int j = i+1; j<n;j++){
            if(arr[j] < arr[i]){
                count++;
            }
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

    cout<<countInversion(arr, n);
    return 0;
}