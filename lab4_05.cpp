/*
--Student Report Card Automation Using Class--

Design a C++ class named Student to automate report card generation for a batch of students.

The class should initialize student details using a constructor, validate marks so that only values between 0 and 100 are accepted (invalid values must be set to 0), compute the average marks automatically, and assign ranks based on student performance where the highest average secures Rank 1.

Five student records are hardcoded in the main() function.

The program must display a formatted report card table showing student details, subject marks, average, and rank.

Input Format

The program uses hardcoded student records with the following attributes:

Line 1 consists of "N" (number of input lines)

"Id Name Physics Chemistry Maths"

Five records are initialized directly in main().

Constraints

Number of students is fixed to 5
Marks must be in the range 0 to 100
Any invalid mark (less than 0 or greater than 100) is treated as 0
Average marks are calculated as:
(Physics + Chemistry + Maths) / 3
Ranking is based on descending order of average marks
No two students share the same rank
Output Format

Display a formatted report card table containing:

"Id Name Physics Chemistry Maths Average Rank"

Each student’s details must appear on a separate line, sorted by rank (highest average first).

Sample Input 0

5
101 Alice 95 92 98
105 Eve 94 91 97
102 Bob 70 65 72
104 David 0 80 85
103 Charlie 40 35 50
Sample Output 0

101 Alice 95 92 98 95.0 1
105 Eve 94 91 97 94.0 2
102 Bob 70 65 72 69.0 3
104 David 0 80 85 55.0 4
103 Charlie 40 35 50 41.7 5
Sample Input 1

5
201 A 80 80 80
202 B 70 70 70
203 C 60 60 60
204 D 90 90 90
205 E 50 50 50
Sample Output 1

204 D 90 90 90 90.0 1
201 A 80 80 80 80.0 2
202 B 70 70 70 70.0 3
203 C 60 60 60 60.0 4
205 E 50 50 50 50.0 5
*/

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

class Student {
private:
    int id;
    string name;
    int physics;
    int chemistry;
    int maths;
    double average;
    int rank;

    int validateMark(int mark) {
        if (mark < 0 || mark > 100) {
            return 0;
        }
        return mark;
    }

public:
    Student(int id, string name, int p, int c, int m) 
        : id(id), name(name), rank(0) {
        physics = validateMark(p);
        chemistry = validateMark(c);
        maths = validateMark(m);
        average = (physics + chemistry + maths) / 3.0;
    }

    double getAverage() const {
        return average;
    }

    void setRank(int r) {
        rank = r;
    }

    void display() const {
        cout << id << " " 
             << name << " " 
             << physics << " " 
             << chemistry << " " 
             << maths << " " 
             << fixed << setprecision(1) << average << " " 
             << rank << "\n";
    }
};

int main() {
    int n;
    vector<Student> students;

    if (cin >> n) {
        for (int i = 0; i < n; ++i) {
            int id, p, c, m;
            string name;
            cin >> id >> name >> p >> c >> m;
            students.emplace_back(id, name, p, c, m);
        }
    } else {
        students = {
            Student(101, "Alice", 95, 92, 98),
            Student(105, "Eve", 94, 91, 97),
            Student(102, "Bob", 70, 65, 72),
            Student(104, "David", 0, 80, 85),
            Student(103, "Charlie", 40, 35, 50)
        };
    }

    sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.getAverage() > b.getAverage();
    });

    for (size_t i = 0; i < students.size(); ++i) {
        students[i].setRank(i + 1);
        students[i].display();
    }

    return 0;
}