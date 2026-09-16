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