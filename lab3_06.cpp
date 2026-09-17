/*
--K-th Smallest Pair Distance--

Given an integer array nums and an integer k, consider all possible pairs of elements nums[i] and nums[j] where 0 <= i < j < nums.length.

The distance of a pair is defined as the absolute difference between the two numbers:

|nums[i] - nums[j]|

Your task is to find and return the k-th smallest pair distance among all possible pairs.

For example, for nums = [1, 3, 1], the possible pairs are:

(1, 3) → distance 2
(1, 1) → distance 0
(3, 1) → distance 2
The sorted distances are [0, 2, 2].

Therefore, when k = 1, the answer is 0.

(Hint: Try using 2 pointer approch and Binary Search if you know)

Input Format

The first line contains an integer n, representing the number of elements in the array.

The second line contains n space-separated integers representing the array nums.

The third line contains an integer k, representing the required position in the sorted list of pair distances.

Constraints

2 <= n <= 10^4
0 <= nums[i] <= 10^6
1 <= k <= n * (n - 1) / 2
All pair distances must be considered based on indices i < j.
The solution should be efficient enough to handle the maximum input size.
Output Format

Print a single integer representing the k-th smallest pair distance.

Sample Input 0

3 
1 3 1
1    
Sample Output 0

0
Sample Input 1

3 
1 6 1 
3
Sample Output 1

5
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long countPairs(const vector<int>& nums, int maxDist) {
    long long count = 0;
    int left = 0;
    int n = nums.size();
    
    for (int right = 0; right < n; ++right) {
        while (nums[right] - nums[left] > maxDist) {
            left++;
        }
        count += (right - left);
    }
    
    return count;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    long long k;
    cin >> k;

    sort(nums.begin(), nums.end());

    int low = 0;
    int high = nums.back() - nums.front();

    while (low < high) {
        int mid = low + (high - low) / 2;
        
        long long count = countPairs(nums, mid);

        if (count >= k) {
            high = mid; 
        } else {
            low = mid + 1;
        }
    }

    cout << low << "\n";

    return 0;
}
