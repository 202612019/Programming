/*
--Employee Payroll Using Multilevel Inheritance--

Create a C++ program using multilevel inheritance with the following class hierarchy:
Employee
↓
PermanentEmployee
↓
Payroll

The Employee class contains:
name as a protected member
id as a private member
The PermanentEmployee class contains:
basicSalary as a protected member
The Payroll class calculates the final salary.
The final salary is calculated using the following rules:
HRA = 20% of basic salary
DA = 10% of basic salary
Final Salary = Basic Salary + HRA + DA
The employee ID must be accessed through a public member function of the Employee class.
The derived classes should directly access the protected members.
Your program must demonstrate the use of multilevel inheritance and access control in C++.
Do not use polymorphism or virtual functions.

Input Format:-
The first line contains the employee's name.
The second line contains an integer ID representing the employee ID.
The third line contains the employee's basic salary.
Constraints

1 ≤ ID ≤ 100000
1000 ≤ Basic Salary ≤ 1000000\

Output Format:-
Print the employee details in the following format:
Name:
ID:
Basic Salary:
Final Salary:
Print the salary values with two digits after the decimal point.

Sample Input 0:-

Neha
10
1000

Sample Output 0:-

Name: Neha
ID: 10
Basic Salary: 1000.00
Final Salary: 1300.00
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Employee{
    private:
        int id;
    protected:
        string name;
    public:
        void setId(string n, int i){
            id = i;
            name = n;
        }
        void displayId(){
            cout<<"Name: "<<name<<endl;
            cout<<"ID: "<<id<<endl;
        }
        
};

class PermanentEmployee : public Employee{
    protected:
        double basicSalary;
    public:
        void setbSa(int b){
            basicSalary = b;
        }
        void displaybSa(){
            cout<<"Basic Salary: "<< fixed << setprecision(2) <<basicSalary<<endl;
        }
};

class Payroll : public PermanentEmployee{
    protected:
        double finalSal;
    public:
        void finalC(){
            double HRA = basicSalary * 20.0 /100.0;
            double DA = basicSalary * 10.0 /100.0;
            finalSal = basicSalary + HRA + DA;
        }
        void displayfin(){
            cout<<"Final Salary: "<< fixed << setprecision(2) <<finalSal<<endl;
        }
        
};

int main() {
    
    string n;
    cin >> n;
    int id;
    cin>>id;
    int bSal;
    cin>>bSal;
    
    Payroll p;
    p.setId(n, id);
    p.displayId();
    p.setbSa(bSal);
    p.displaybSa();
    p.finalC();
    p.displayfin();
    
    return 0;
}