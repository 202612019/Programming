/*
--The Employee Payroll System--

A company wants to develop an employee payroll system that calculates salaries for three categories of employees:

Permanent Employee (P): Receives a fixed monthly salary plus a bonus.
Contract Employee (C): Receives payment based on the number of hours worked and the hourly rate.
Intern (I): Receives a fixed stipend plus a performance bonus.
You must implement an abstract base class named Employee and derive three classes from it: PermanentEmployee, ContractEmployee, and Intern.

The Employee class must declare a pure virtual function named calculateSalary() that returns the employee's monthly salary. Each derived class must implement this function according to its salary calculation rules.

The base class must also define a non-virtual function named displayType() that prints Employee: General. Each derived class must define a function with the same name that prints its specific employee type. When called through a base-class pointer, the non-virtual function must demonstrate early binding.

The calculateSalary() function must demonstrate late binding by invoking the appropriate derived-class implementation through a base-class pointer.

The base class must have a virtual destructor, and each derived class must have its own destructor. All employees must be processed in input order and deleted through base-class pointers.

Salary calculation rules 1. Permanent Employee (P)

Input: basicSalary bonus

Salary = basicSalary + bonus

Contract Employee (C)

Input: hoursWorked hourlyRate

Salary = hoursWorked x hourlyRate

Intern (I)

Input: stipend performanceBonus

Salary = stipend + performanceBonus

For each employee, the program must print the employee category and calculated salary. After processing all employees, it must delete the objects in input order and print the derived-class destructor message followed by the base-class destructor message.

Input Format

The first line contains an integer (N), representing the number of employees.
Each of the next (N) lines begins with a character identifying the employee type:
P — Permanent employee, followed by basicSalary and bonus.
C — Contract employee, followed by hoursWorked and hourlyRate.
I — Intern, followed by stipend and performanceBonus.
All numeric inputs are positive or non-negative values as permitted by the constraints.

Constraints

1 <= N <= 100
0 <= basicSalary, bonus, stipend, performanceBonus <= 10^7
0 <= hoursWorkded <= 10^4
0 <= hoursRate <= 10^5

Employee types will only be P, C, or I.

Each employee record contains exactly the parameters required for its type.
Calculated salaries must be printed with exactly two digits after the decimal point.
Employee must be an abstract class.
calculateSalary() must be a pure virtual function.
All employee objects must be accessed and deleted through base-class pointers.
The base-class destructor must be virtual.
Employees must be processed and destroyed in input order.
Output Format

For every employee, print two lines:

The employee category:
Employee: General for all employees when called through a base-class pointer.
The calculated salary in one of these formats:
Salary: X.XX
After printing the salaries for all employees, print two destructor messages for each employee, in input order:

Permanent employee: PermanentEmployee destructor, followed by Employee destructor.
Contract employee: ContractEmployee destructor, followed by Employee destructor.
Intern: Intern destructor, followed by Employee destructor.
Each message must appear on a separate line.

Sample Input 0

3
P 30000 5000
C 160 250
I 10000 1500
Sample Output 0

Employee: General
Salary: 35000.00
Employee: General
Salary: 40000.00
Employee: General
Salary: 11500.00
PermanentEmployee destructor
Employee destructor
ContractEmployee destructor
Employee destructor
Intern destructor
Employee destructor
Explanation 0

Permanent employee: (30000 + 5000 = 35000)
Contract employee: (160 \times 250 = 40000)
Intern: (10000 + 1500 = 11500)
The non-virtual displayType() function demonstrates early binding, so Employee: General is printed for every employee. The pure virtual calculateSalary() function is implemented by each derived class and demonstrates late binding.

When the objects are deleted through Employee*, the appropriate derived destructor executes before the base-class destructor.
*/

#include <vector>
#include <iostream>
#include<iomanip>
using namespace std;

class Employee{
    private:
        
    public:
        virtual ~Employee(){
            cout<<"Employee destructor"<<endl;
        }
        virtual double calculateSalary() const = 0;
        
        void displayType(){
            cout<<"Employee: General"<<endl;
        }
};

class PermanentEmployee: public Employee{
    private:
        double salary;
        double bonus;
    public:
        PermanentEmployee(double s, double b) : salary(s), bonus(b) {}
        double calculateSalary() const override{
            return salary+bonus;
        }
        void displayType() const{
            cout<<"Employee: Permanent"<<endl;
        }
        ~PermanentEmployee() override{
            cout<<"PermanentEmployee destructor"<<endl;
        }
        
};

class ContractEmployee : public Employee{
    private:
        double hourworked;
        double hourrate;
    public:
        ContractEmployee(double hw, double hr) : hourworked(hw), hourrate(hr) {}
        double calculateSalary() const override{
            return hourworked * hourrate;
        }
        void displayType() const{
            cout<<"Employee: Contract"<<endl;
        }
        ~ContractEmployee() override{
            cout<<"ContractEmployee destructor"<<endl;
        }
        
};

class Intern : public Employee{
    private:
        double stipend;
        double performanceBonus;
    public:
        Intern(double s, double pb) : stipend(s), performanceBonus(pb) {}
        double calculateSalary() const override{
            return stipend + performanceBonus;
        }
        void displayType() const{
            cout<<"Employee: Intern"<<endl;
        }
        ~Intern() override{
            cout<<"Intern destructor"<<endl;
        }
};

int main() {
    
    int n;
    cin >> n;

    vector<Employee*> employees;

    for (int i = 0; i < n; ++i) {
        char type;
        cin >> type;
        
        if (type == 'P') {
            double basicSalary, bonus;
            cin >> basicSalary >> bonus;
            employees.push_back(new PermanentEmployee(basicSalary, bonus));
        } else if (type == 'C') {
            double hoursWorked, hourlyRate;
            cin >> hoursWorked >> hourlyRate;
            employees.push_back(new ContractEmployee(hoursWorked, hourlyRate));
        } else if (type == 'I') {
            double stipend, performanceBonus;
            cin >> stipend >> performanceBonus;
            employees.push_back(new Intern(stipend, performanceBonus));
        }
    }

    for (Employee* emp : employees) {
        emp->displayType();
        cout << "Salary: " << fixed << setprecision(2) << emp->calculateSalary() << "\n";
    }

    for (Employee* emp : employees) {
        delete emp; 
    }
    
    return 0;
}
