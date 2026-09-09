#include <iostream>
using namespace std;

class Employee {
private:
    static int activeEmployees;
    static int totalEmployees;

public:
    Employee() {
        activeEmployees++;
        totalEmployees++;
    }

    ~Employee() {
        activeEmployees--;
    }

    static int getActiveEmployees() {
        return activeEmployees;
    }

    static int getTotalEmployees() {
        return totalEmployees;
    }
};

int Employee::activeEmployees = 0;
int Employee::totalEmployees = 0;

int main() {
    int n, k;
    
    cin >> n >> k;

    Employee** employees = new Employee*[n];

    for (int i = 0; i < n; i++) {
        employees[i] = new Employee();
    }

    for (int i = 0; i < k; i++) {
        delete employees[i];
        employees[i] = nullptr; 
    }

    cout << "Active Employees: " << Employee::getActiveEmployees() << endl;
    cout << "Total Employees: " << Employee::getTotalEmployees() << endl;

    for (int i = k; i < n; i++) {
        delete employees[i];
    }
    delete[] employees;

    return 0;
}