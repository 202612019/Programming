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