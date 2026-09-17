/*
--3 Sum--

Given an integer array nums, find all unique triplets [nums[i], nums[j], nums[k]] such that:

i, j, and k are three different indices.
nums[i] + nums[j] + nums[k] == 0.
The solution must not contain duplicate triplets.

The same element value may be used more than once if it appears at different indices. However, the same combination of values should appear only once in the output.

Each triplet should be arranged in non-decreasing order.

The order of the triplets in the final output does not matter.

Example 1

Input

6 2 -2 0 3 -3 5

Output

-3 -2 5 -3 0 3 -2 0 2

Explanation:

The valid triplets are:

-2 + 0 + 2 = 0 -3 + -2 + 5 = 0 -3 + 0 + 3 = 0

Therefore, there are 3 unique triplets.

Example 2

Input

5 2 -1 -1 3 -1

Output

-1 -1 2

Explanation:

The two -1 values at different indices can be used together:

-1 + -1 + 2 = 0

Although there are three occurrences of -1, the triplet [-1, -1, 2] is included only once because duplicate triplets are not allowed.

Input Format

The first line contains an integer N, representing the number of elements in the array.
The second line contains N space-separated integers representing the elements of the array.
Constraints

3 <= N <= 3000
-10^5 <= nums[i] <= 10^5
Output Format

The first line should contain an integer K, representing the number of unique triplets found.
The next K lines should each contain three space-separated integers representing one valid triplet.
Each triplet must be printed in non-decreasing order.
If no valid triplet exists, print 0 only.
The order in which the triplets are printed does not matter.
Sample Input 0

6
2 -2 0 3 -3 5
Sample Output 0

3
-3 -2 5
-3 0 3
-2 0 2
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> nums(N);

    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    vector<vector<int>> result;

    for (int i = 0; i < N - 2; i++) {

        // Skip duplicate first numbers
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        int left = i + 1;
        int right = N - 1;

        while (left < right) {

            int sum = nums[i] + nums[left] + nums[right];

            if (sum == 0) {

                result.push_back({
                    nums[i],
                    nums[left],
                    nums[right]
                });

                left++;
                right--;

            }
            else if (sum < 0) {
                left++;
            }
            else {
                right--;
            }
        }
    }

    cout << result.size() << endl;

    for (auto triplet : result) {
        cout << triplet[0] << " "
             << triplet[1] << " "
             << triplet[2] << endl;
    }

    return 0;
}