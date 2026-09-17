/*
--Merge two sorted arrays without extra space--

Given two integer arrays nums1 and nums2, both sorted in non-decreasing order, merge them into a single sorted array.

The merged array must be stored inside nums1 and the merging must be performed in-place, without using another array to store the final result.

nums1 has a length of m + n.
The first m elements of nums1 contain the actual elements.
The remaining n positions in nums1 contain 0 as empty spaces.
nums2 contains n elements.
The final nums1 array should contain all m + n elements in non-decreasing order.

Example 1

Input

4 3 -5 -2 4 5 -3 1 8

Output

-5 -3 -2 1 4 5 8

Explanation:

The first 4 elements of nums1 are:

[-5, -2, 4, 5]

The elements of nums2 are:

[-3, 1, 8]

After merging:

[-5, -3, -2, 1, 4, 5, 8]

The result is stored inside nums1.

Example 2

Input

4 3 0 2 7 8 -7 -3 -1

Output

-7 -3 -1 0 2 7 8

Explanation:

The merged array is:

[-7, -3, -1, 0, 2, 7, 8]

The original elements of nums1 and nums2 are merged while maintaining sorted order.

Input Format

The first line contains two space-separated integers m and n.
The second line contains m space-separated integers representing the actual elements of nums1.
The third line contains n space-separated integers representing nums2. The n empty positions at the end of nums1 are not provided separately because they are reserved automatically.
Constraints

0 <= m, n <= 10^5
1 <= m + n <= 2 * 10^5
-10^9 <= nums1[i], nums2[i] <= 10^9
nums1 is sorted in non-decreasing order.
nums2 is sorted in non-decreasing order.
Output Format

Print the final merged array containing all m + n elements in non-decreasing order.

The result must represent the final contents of nums1 after the in-place merge.

Important Notes

The 0s mentioned in the original nums1 array are empty spaces, not actual elements.
If 0 is a valid element of nums1, it must still be treated as an actual element when it occurs within the first m positions.
Duplicate values are allowed.
The final array must contain every element from both arrays exactly once.
The expected approach should use O(1) extra space.
Sample Input 0

4 3
-5 -2 4 5
-3 1 8
Sample Output 0

-5 -3 -2 1 4 5 8
*/

#include <iostream>
using namespace std;

int main() {

    int m, n;
    cin >> m >> n;

    long long nums1[m + n];
    for (int i = 0; i < m; ++i) {
        cin >> nums1[i];
    }

    long long nums2[n];
    for (int i = 0; i < n; ++i) {
        cin >> nums2[i];
    }

    int p1 = m - 1;
    int p2 = n - 1;
    int p = m + n - 1;

    while (p1 >= 0 && p2 >= 0) {
        if (nums1[p1] > nums2[p2]) {
            nums1[p] = nums1[p1];
            p1--;
        } else {
            nums1[p] = nums2[p2];
            p2--;
        }
        p--;
    }

    while (p2 >= 0) {
        nums1[p] = nums2[p2];
        p2--;
        p--;
    }

    for (int i = 0; i < m + n; ++i) {
        cout << nums1[i] << " ";
    }
    cout << "\n";

    return 0;
}