#include <iostream>
#include <vector>

using namespace std;

int main() {

    int m, n;
    cin >> m >> n;

    vector<long long> nums1(m + n);
    for (int i = 0; i < m; ++i) {
        cin >> nums1[i];
    }

    vector<long long> nums2(n);
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