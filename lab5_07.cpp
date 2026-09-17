/*
--Smart Bank Account Initialization--

Design a C++ class BankAccount that demonstrates constructor overloading as compile-time polymorphism.

The BankAccount class represents a bank account and must support different ways of initializing an account.

Implement the following overloaded constructors:

1.A default constructor that initializes:

Account holder name as "Unknown"
Account number as 0
Balance as 0.0
2.A constructor that accepts only the account holder name and initializes: Account number as 0

Balance as 0.0
3.A constructor that accepts the account holder name and account number and initializes:

Balance as 0.0
4.A constructor that accepts the account holder name, account number, and initial balance.

The program must create objects using different constructors based on the input.

Add uncessary comments and print statements

The constructor selected by the compiler must be determined by the number and type of arguments passed during object creation.

Input Format

The first line contains an integer N, representing the number of bank accounts to create.

The next N lines contain one of the following formats:

0
Creates an account using the default constructor.

1 <name>
Creates an account using the constructor that accepts only the account holder's name.

2 <name> <accountNumber>
Creates an account using the constructor that accepts the name and account number.

3 <name> <accountNumber> <balance>
Creates an account using the constructor that accepts all three values.

Constraints

1 ≤ N ≤ 100
1 ≤ length(name) ≤ 50
name contains only English alphabets.
0 ≤ accountNumber ≤ 10^12
0.0 ≤ balance ≤ 10^9
Balance may contain up to two digits after the decimal point.
Account numbers are non-negative.
Each account must be created using one of the overloaded constructors.
Do not use if/else inside the class to determine which constructor should execute.
The solution must use constructor overloading.
The class must contain all four constructors.
The constructors must initialize the object's data members.
Output Format

For each account, print:

Account Holder: <name>
Account Number: <accountNumber>
Balance: <balance>
Constructor Type: <constructor description>
Print a blank line after each account.

The constructor descriptions must be:

Default Constructor
Name Constructor
Name + Account Number Constructor
Name + Account Number + Balance Constructor
Sample Input 0

4
0
1 Rahul
2 Amit 10025
3 Priya 10026 5000.50
Sample Output 0

Account Holder: Unknown
Account Number: 0
Balance: 0.00
Constructor Type: Default Constructor

Account Holder: Rahul
Account Number: 0
Balance: 0.00
Constructor Type: Name Constructor

Account Holder: Amit
Account Number: 10025
Balance: 0.00
Constructor Type: Name + Account Number Constructor

Account Holder: Priya
Account Number: 10026
Balance: 5000.50
Constructor Type: Name + Account Number + Balance Constructor
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class BankAccount {
private:
    string name;
    long long accountNumber;
    double balance;
    string constructorType;

public:
    BankAccount() {
        name = "Unknown";
        accountNumber = 0;
        balance = 0.0;
        constructorType = "Default Constructor";
    }

    BankAccount(string n) {
        name = n;
        accountNumber = 0;
        balance = 0.0;
        constructorType = "Name Constructor";
    }

    BankAccount(string n, long long acc) {
        name = n;
        accountNumber = acc;
        balance = 0.0;
        constructorType = "Name + Account Number Constructor";
    }

    BankAccount(string n, long long acc, double bal) {
        name = n;
        accountNumber = acc;
        balance = bal;
        constructorType = "Name + Account Number + Balance Constructor";
    }

    void display() const {
        cout << "Account Holder: " << name << "\n";
        cout << "Account Number: " << accountNumber << "\n";
        cout << "Balance: " << fixed << setprecision(2) << balance << "\n";
        cout << "Constructor Type: " << constructorType << "\n\n";
    }
};

int main() {
    int n;
    cin >> n;
    
    for (int i = 0; i < n; ++i) {
        int type;
        cin >> type;
        
        if (type == 0) {
            BankAccount acc;
            acc.display();
        } 
        else if (type == 1) {
            string name;
            cin >> name;
            BankAccount acc(name);
            acc.display();
        } 
        else if (type == 2) {
            string name;
            long long accNum;
            cin >> name >> accNum;
            BankAccount acc(name, accNum);
            acc.display();
        } 
        else if (type == 3) {
            string name;
            long long accNum;
            double bal;
            cin >> name >> accNum >> bal;
            BankAccount acc(name, accNum, bal);
            acc.display();
        }
    }
    
    return 0;
}