/*
--Set Operations on Two Collections--

Given two collections of integers, find their union, intersection, and difference.

Union: All distinct elements present in either collection.
Intersection: Elements present in both collections.
Difference: Elements present in the first collection but not in the second.
Implement a class template SetProcessor using STL containers and algorithms. Sort the input collections and remove duplicates before applying set_union(), set_intersection(), and set_difference().

Input Format

The first line contains two integers N and M, representing the sizes of the collections.
The second line contains N integers representing the first collection.
The third line contains M integers representing the second collection.
Constraints

(1 <= N,M <= 10^5)
(-10^9 <= A[i],B[i] <= 10^9)
Input collections may contain duplicate elements.
Output Format

Print three lines:

Union: followed by the union elements.
Intersection: followed by the intersection elements.
Difference: followed by the elements present only in the first collection.
Print elements in ascending order, separated by spaces. If a result is empty, print only its label.

Sample Input 0

5 4
1 2 3 4 5
3 4 5 6
Sample Output 0

Union: 1 2 3 4 5 6
Intersection: 3 4 5
Difference: 1 2
Explanation 0

The union contains every distinct element from both collections. The intersection contains 3, 4, and 5, which occur in both. The difference contains 1 and 2, which occur only in the first collection.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

template <typename T>
class SetProcessor {
    private:
        vector<T> collection1;
        vector<T> collection2;
        
        void prepareCollection(vector<T>& vec) {
            sort(vec.begin(), vec.end());
            vec.erase(unique(vec.begin(), vec.end()), vec.end());
        }

        void printCollection(const string& label, const vector<T>& vec) {
            cout << label;
            if (!vec.empty()) {
                cout << " ";
                for (size_t i = 0; i < vec.size(); ++i) {
                    cout << vec[i] << (i == vec.size() - 1 ? "" : " ");
                }
            }
            std::cout << "\n";
        }

    public:
        SetProcessor(vector<T> c1, vector<T> c2) : collection1(c1), collection2(c2) {
            prepareCollection(collection1);
            prepareCollection(collection2);
        }

        void processAndPrint() {
            vector<T> unionResult;
            vector<T> intersectionResult;
            vector<T> differenceResult;

            set_union(
                collection1.begin(), collection1.end(),
                collection2.begin(), collection2.end(),
                back_inserter(unionResult)
            );

            set_intersection(
                collection1.begin(), collection1.end(),
                collection2.begin(), collection2.end(),
                back_inserter(intersectionResult)
            );

            set_difference(
                collection1.begin(), collection1.end(),
                collection2.begin(), collection2.end(),
                back_inserter(differenceResult)
            );

            printCollection("Union:", unionResult);
            printCollection("Intersection:", intersectionResult);
            printCollection("Difference:", differenceResult);
        }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<long long> c1(n);
    vector<long long> c2(m);

    for (int i = 0; i < n; ++i) {
        cin >> c1[i];
    }

    for (int i = 0; i < m; ++i) {
        cin >> c2[i];
    }

    SetProcessor<long long> processor(c1, c2);    
    processor.processAndPrint();

    return 0;
}