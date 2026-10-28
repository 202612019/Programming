/*
--Find the K Most Frequent Elements--

Given an array of N integers and an integer K, find the K most frequently occurring distinct elements.

Print the selected elements in decreasing order of frequency. If two elements have the same frequency, the smaller element must appear first.

Implement a class template FrequencyAnalyzer using an STL map to count frequencies and STL algorithms to sort the results.

Input Format

The first line contains two integers N and K.
The second line contains N integers representing the array elements.
Constraints

(1 <= N <= 10^5)
(1 <= K <= D), where D is the number of distinct elements.
(-10^9 <= A[i] <= 10^9)
Output Format

Print the K most frequent distinct elements in a single line, separated by spaces, in decreasing order of frequency. For equal frequencies, print the smaller element first.

Sample Input 0

6 2
1 1 1 2 2 3
Sample Output 0

1 2
Explanation 0

Element 1 occurs three times, 2 occurs twice, and 3 occurs once. Therefore, the two most frequent elements are 1 and 2.
*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

template <typename T>
class FrequencyAnalyzer {
    private:
        map<T, int> freqMap;

    public:
        void addElement(T value) {
            freqMap[value]++;
        }
        
        vector<T> getTopK(int k) {
            vector<pair<T, int>> freqVec(freqMap.begin(), freqMap.end());

            sort(freqVec.begin(), freqVec.end(), [](const pair<T, int>& a, const pair<T, int>& b) {
                if (a.second != b.second) {
                    return a.second > b.second;
                }
                return a.first < b.first;
            });

            vector<T> result;
            for (int i = 0; i < k && i < freqVec.size(); ++i) {
                result.push_back(freqVec[i].first);
            }

            return result;
        }
};

int main() {
    
    int n, k;
    cin >> n >> k;
    FrequencyAnalyzer<long long> analyzer; 

    for (int i = 0; i < n; ++i) {
        long long val;
        cin >> val;
        analyzer.addElement(val);
    }

    vector<long long> result = analyzer.getTopK(k);

    for (size_t i = 0; i < result.size(); ++i) {
        cout << result[i] << (i == result.size() - 1 ? "" : " ");
    }
    cout << "\n";
    

    return 0;
}