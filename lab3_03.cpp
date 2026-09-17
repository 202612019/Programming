/*
--Employee Object Lifecycle Tracker--

Create a C++ class named Employee that keeps track of the number of Employee objects currently alive as well as the total number of objects ever created.

The class must contain the following static data members: static int activeEmployees; static int totalEmployees;

Requirements

When an Employee object is created, increment both activeEmployees and totalEmployees by 1.
When an Employee object is destroyed, decrement activeEmployees by 1.
totalEmployees must never decrease because it represents the total number of objects created during the program.
Create the following static member functions: static int getActiveEmployees(); static int getTotalEmployees();
Both functions must return their corresponding static data members.
The static data members must be defined outside the class using the scope resolution operator ::.
The program must use a constructor to update the counters when an object is created.
The program must use a destructor to update activeEmployees when an object is destroyed.
The program must dynamically create some Employee objects using new and release them using delete.
Do not use global variables to maintain the counters.
Input Format

The first line contains an integer N, representing the number of Employee objects to create dynamically.

The second line contains an integer K, representing the number of dynamically allocated objects that will be deleted before the program ends.

Constraints

1 <= N <= 100000 0 <= K <= N

Output Format

Active Employees: Total Employees:

Sample Input 0

5
2
Sample Output 0

Active Employees: 3
Total Employees: 5
Explanation 0

Initially:

Active Employees = 0 Total Employees = 0

The program creates 5 Employee objects.

After creation:

Active Employees = 5 Total Employees = 5

Two of the dynamically allocated objects are then destroyed using delete.

Therefore:

Active Employees = 3 Total Employees = 5

The active count decreases when objects are destroyed, but the total count remains 5 because five objects were created during the program.
*/

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