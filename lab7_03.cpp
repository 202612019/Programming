/*
--Merge Intervals Using Operator Overloading--

Create an Interval class containing start and end.
Overload < to compare two interval objects by their starting values.
Overload == to compare two interval objects.
Overload = to copy one interval object into another.
Implement friend operator<< to display an interval.
Sort the intervals using the overloaded < operator.
Merge all overlapping intervals.
Return the resulting non-overlapping intervals.
Input Format

The first line contains the number of intervals.
Each interval contains two integers: start and end.
Intervals may be given in arbitrary order.
Two intervals overlap when the next interval starts before or at the current interval's end.
Use the overloaded operators while processing the intervals.
Constraints

1 <= intervals.length <= 10^4

intervals[i].length == 2

0 <= start_i <= end_i <= 10^4

Intervals may be unsorted.

Intervals sharing an endpoint are considered overlapping.

The output must contain non-overlapping intervals.

Output Format

Output all merged intervals.
Each interval must be represented as [start,end].
The intervals must be sorted by their starting value.
Overlapping intervals must be combined

Sample Input 0
intervals = [[1,3],[2,6],[8,10],[15,18]]

Sample Output 0
[[1,6],[8,10],[15,18]]
*/
    
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

class Interval {
public:
    int start;
    int end;

    Interval(int s = 0, int e = 0) : start(s), end(e) {}

    bool operator<(const Interval& other) const {
        return this->start < other.start;
    }

    bool operator==(const Interval& other) const {
        return this->start == other.start && this->end == other.end;
    }

    Interval& operator=(const Interval& other) {
        if (this != &other) {
            this->start = other.start;
            this->end = other.end;
        }
        return *this;
    }

    friend ostream& operator<<(ostream& os, const Interval& interval) {
        os << "[" << interval.start << "," << interval.end << "]";
        return os;
    }
};

int main() {

    string input;
    char c;
    while (cin >> c) {
        input += c;
    }

    vector<int> nums;
    string current_num = "";
    for (char ch : input) {
        if (isdigit(ch)) {
            current_num += ch;
        } else {
            if (!current_num.empty()) {
                nums.push_back(stoi(current_num));
                current_num = "";
            }
        }
    }
    if (!current_num.empty()) {
        nums.push_back(stoi(current_num));
    }

    int start_idx = (nums.size() % 2 != 0) ? 1 : 0;

    vector<Interval> intervals;
    for (size_t i = start_idx; i + 1 < nums.size(); i += 2) {
        intervals.push_back(Interval(nums[i], nums[i + 1]));
    }

    if (intervals.empty()) {
        cout << "[]\n";
        return 0;
    }

    sort(intervals.begin(), intervals.end());

    vector<Interval> merged;
    merged.push_back(intervals[0]);

    for (size_t i = 1; i < intervals.size(); ++i) {
        Interval& last = merged.back();
        
        if (intervals[i].start <= last.end) {
            last.end = max(last.end, intervals[i].end);
        } else {
            merged.push_back(intervals[i]);
        }
    }

    cout << "[";
    for (size_t i = 0; i < merged.size(); ++i) {
        cout << merged[i];
        if (i != merged.size() - 1) {
            cout << ",";
        }
    }
    cout << "]\n";

    return 0;
}