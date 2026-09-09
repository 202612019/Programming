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