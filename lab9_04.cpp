/*
--Merge K Sorted Sequences--

You are given (K) sorted sequences, each containing a different number of integers. Your task is to merge all sequences into one sorted sequence.

Implement a class template named KWayMerger that uses STL containers and a priority_queue to efficiently merge the sequences.

You must not combine all elements first and then sort the complete collection. Instead, use a min-heap to select the smallest available element from the sequences.

Input Format

The first line contains an integer K, the number of sequences.
The next K lines each begin with an integer N_i, followed by N_i sorted integers.
Constraints

1 <= K <= 10^3
1 <= N_i <= 10^4
The total number of elements does not exceed 10^5.
-10^9 <= A_{ij} <= 10^9
Every input sequence is sorted in non-decreasing order.
Output Format

Print all elements from the merged sequence in ascending order, separated by spaces.

Sample Input 0

3
4 1 4 7 10
3 2 5 8
4 3 6 9 11
Sample Output 0

1 2 3 4 5 6 7 8 9 10 11
Explanation 0

The three sorted sequences are merged into one sorted sequence using a min-heap. At each step, the smallest available element is removed from the heap, printed, and replaced with the next element from the same sequence, if one exists
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <typename T>
class KWayMerger {
    private:
        struct Node {
            T value;
            int seq_idx;
            int elem_idx;

            bool operator>(const Node& other) const {
                return value > other.value;
            }
        };

        vector<vector<T>> sequences;

    public:
        void addSequence(const vector<T>& seq) {
            sequences.push_back(seq);
        }

        vector<T> merge() {
            vector<T> result;
            
            priority_queue<Node, vector<Node>, greater<Node>> pq;

            for (size_t i = 0; i < sequences.size(); ++i) {
                if (!sequences[i].empty()) {
                    pq.push({sequences[i][0], static_cast<int>(i), 0});
                }
            }

            while (!pq.empty()) {
                Node current = pq.top();
                pq.pop();

                result.push_back(current.value);

                int next_elem_idx = current.elem_idx + 1;

                if (next_elem_idx < sequences[current.seq_idx].size()) {
                    pq.push({sequences[current.seq_idx][next_elem_idx], current.seq_idx, next_elem_idx});
                }
            }

            return result;
        }
};

int main() {
    
    int k;
    cin >> k;
    
    KWayMerger<long long> merger;

    for (int i = 0; i < k; ++i) {
        int n;
        cin >> n;
        vector<long long> seq(n);
        for (int j = 0; j < n; ++j) {
            cin >> seq[j];
        }
        merger.addSequence(seq);
    }

    vector<long long> result = merger.merge();

    for (size_t i = 0; i < result.size(); ++i) {
        cout << result[i] << (i == result.size() - 1 ? "" : " ");
    }
    cout << "\n";

    return 0;
}