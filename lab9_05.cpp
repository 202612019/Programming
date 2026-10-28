/*
--Advanced Collection Analyzer--

You are given two collections of integers. Each collection may contain duplicate elements and may not be sorted.

Implement a class template named CollectionAnalyzer that performs the following operations:

Union: Find all distinct elements present in either collection.
Intersection: Find all distinct elements present in both collections.
Difference: Find all distinct elements present in the first collection but not in the second.
Symmetric Difference: Find all distinct elements present in exactly one of the two collections.
Before applying the STL set algorithms, sort both collections and remove duplicate elements using sort() and unique().

Print the result of each operation in ascending order.

Input Format

The first line contains two integers, N and M, representing the sizes of the collections.
The second line contains N integers.
The third line contains M integers.
Constraints

1 <= N,M <= 10^5
-10^9 <= A_i,B_i <= 10^9
Duplicate elements are allowed.
Output Format

Print four lines in the following format:

Union: followed by the union elements.
Intersection: followed by the intersection elements.
Difference: followed by the difference elements.
Symmetric Difference: followed by the symmetric difference elements.
Print only the label if an operation produces an empty collection.

Sample Input 0

6 5
1 2 2 3 5 5
2 3 3 4 6
Sample Output 0

Union: 1 2 3 4 5 6
Intersection: 2 3
Difference: 1 5
Symmetric Difference: 1 4 5 6
Explanation 0

Duplicates are removed first. The union contains all distinct elements, the intersection contains common elements, the difference contains elements found only in the first collection, and the symmetric difference contains elements found in exactly one collection.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

template <typename T>
class CollectionAnalyzer {
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
        cout << "\n";
    }

public:
    CollectionAnalyzer(vector<T> c1, vector<T> c2) 
        : collection1(c1), collection2(c2) {
        prepareCollection(collection1);
        prepareCollection(collection2);
    }

    void processAndPrint() {
        vector<T> unionResult;
        vector<T> intersectionResult;
        vector<T> differenceResult;
        vector<T> symDifferenceResult;

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

        set_symmetric_difference(
            collection1.begin(), collection1.end(),
            collection2.begin(), collection2.end(),
            back_inserter(symDifferenceResult)
        );

        printCollection("Union:", unionResult);
        printCollection("Intersection:", intersectionResult);
        printCollection("Difference:", differenceResult);
        printCollection("Symmetric Difference:", symDifferenceResult);
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

    CollectionAnalyzer<long long> analyzer(c1, c2);
    
    analyzer.processAndPrint();

    return 0;
}