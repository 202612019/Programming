/*
--Average Marks Using Constructor and Destructor--

You are given an integer N followed by N integer marks of a student.

Create a class StudentMarks that:

Uses a constructor to store N marks in an array
Uses a member function average() to calculate the average marks
Uses a destructor (even if it is simple)
Uses array indexing only (do not use STL containers)
The program must compute and print the average of the marks using integer division.
Input Format

The first line contains an integer N
The second line contains N space-separated integers representing the marks
N

m1 m2 m3 ... mN

Constraints

1 <= N <= 100 0 <= marks[i] <= 100
Output Format

Print a single integer representing the average marks of the student using integer division.

Sample Input 0

5
60 70 80 90 100
Sample Output 0

80
*/

#include <iostream>
using namespace std;

class StudentMarks {
private:
    int* marks;
    int N;

public:
    StudentMarks(int n, int* inputMarks) {
        N = n;
        marks = new int[N];
        for (int i = 0; i < N; i++) {
            marks[i] = inputMarks[i];
        }
    }

    int average() {
        if (N == 0) return 0;
        int sum = 0;
        for (int i = 0; i < N; i++) {
            sum += marks[i];
        }
        return sum / N;
    }
    
    ~StudentMarks() {
        delete[] marks;
    }
};

int main() {
    int N;
    
    cin >> N;
    
    int* inputMarks = new int[N];
    
    for (int i = 0; i < N; i++) {
        cin >> inputMarks[i];
    }

    StudentMarks student(N, inputMarks);
    cout << student.average() << "\n";

    delete[] inputMarks;
    
    return 0;
}