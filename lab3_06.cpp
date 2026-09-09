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
