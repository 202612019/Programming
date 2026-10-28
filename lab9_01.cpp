/*
--Merge Overlapping Intervals--

Given N intervals, where each interval contains a start and an end value, merge all overlapping intervals and print the resulting intervals in ascending order of their start values.

Two intervals overlap if they share at least one point. For example, [1, 3] and [3, 5] should be merged into [1, 5].

Implement a class template IntervalMerger that works with numeric types such as int and double. Use an STL vector to store intervals and the sort() algorithm to arrange them before merging.

Input Format

The first line contains an integer N, representing the number of intervals.
The next N lines contain two values, start and end, representing each interval.
Constraints

1 <= N <= 10^5
Start value must be less than or equal to end value.
All interval values are integers within the range (-10^9) to (10^9).
Output Format

Print each merged interval on a separate line, with its start and end values separated by a space. Print the intervals in ascending order of their start values.

Sample Input 0

4
1 3
2 6
8 10
9 12
Sample Output 0

1 6
8 12
Explanation 0

The intervals [1, 3] and [2, 6] overlap, so they merge into [1, 6]. Similarly, [8, 10] and [9, 12] merge into [8, 12].
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <typename T>
class IntervalMerger {
private:
    vector<pair<T, T>> intervals;

public:
    void addInterval(T start, T end) {
        intervals.push_back({start, end});
    }

    vector<pair<T, T>> mergeIntervals() {
        if (intervals.empty()) {
            return {};
        }

        sort(intervals.begin(), intervals.end());

        vector<pair<T, T>> mergedIntervals;
        
        T current_start = intervals[0].first;
        T current_end = intervals[0].second;

        for (size_t i = 1; i < intervals.size(); ++i) {
            if (intervals[i].first <= current_end) {
                current_end = max(current_end, intervals[i].second);
            } else {
                mergedIntervals.push_back({current_start, current_end});
                current_start = intervals[i].first;
                current_end = intervals[i].second;
            }
        }
        
        mergedIntervals.push_back({current_start, current_end});

        return mergedIntervals;
    }
};

int main() {

    int n;
    cin >> n; 
    IntervalMerger<long long> merger; 
    
    for (int i = 0; i < n; ++i) {
        long long start, end;
        cin >> start >> end;
        merger.addInterval(start, end);
    }

    vector<pair<long long, long long>> result = merger.mergeIntervals();

    for (const auto& interval : result) {
        cout << interval.first << " " << interval.second << "\n";
    }

    return 0;
}
