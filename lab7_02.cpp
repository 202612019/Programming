/*
--Bank Account Using Hierarchical Inheritance--

Create a C++ program using hierarchical inheritance.
The base class is Account.
Two classes, Savings and Current, should inherit from Account.
The Account class should contain:
accountNumber as a private member.
balance as a protected member.
Create the following derived classes:
Savings
The Savings class calculates the final balance after adding 5% interest.
Interest = Balance * 5 / 100
Final Balance = Balance + Interest
Current
The Current class calculates the final balance after deducting a service charge of 500.
Final Balance = Balance - 500
The account number must be accessed through a public member function of the Account class.
The derived classes must directly access the protected balance member.
Your program must demonstrate hierarchical inheritance and access control in C++.
Do not use polymorphism or virtual functions.
List Item
Input Format

The first line contains an integer representing the account number.
The second line contains the initial account balance.
The third line contains an integer representing the account type:
1 for Savings Account
2 for Current Account
Constraints

1000 ≤ accountNumber ≤ 999999
1000 ≤ balance ≤ 10000000
accountType ∈ {1, 2}
Output Format

For a Savings Account, print:
Account Number:
Account Type: Savings
Final Balance:
For a Current Account, print:
Account Number:
Account Type: Current
Final Balance:
Print the final balance with two digits after the decimal point.
Sample Input 0

67890
10000
2
Sample Output 0

Account Number: 67890
Account Type: Current
Final Balance: 9500.00
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Account {
    private:
        int accountNumber;
    protected:
        double balance;
    public:
        void setAccNo(int n, double b) {
            accountNumber = n;
            balance = b;
        }
        void displayAcc() {
            cout << "Account Number: " << accountNumber << endl;
        }
};

class Savings : public Account {
    public:
        double interest;
        double fin;
        string type = "Savings";
        
        void cal() {
            interest = balance * 5.0 / 100.0;
            fin = balance + interest;
        }
        void displaySa() {
            cout << "Account Type: " << type << endl;
            cout << "Final Balance: " << fixed << setprecision(2) << fin << endl;
        }
};

class Current : public Account {
    public:
        double charge = 500.0;
        double fin;
        string type = "Current";
        
        void cal() {
            fin = balance - charge;
        }
        void displayCu() {
            cout << "Account Type: " << type << endl;
            cout << "Final Balance: " << fixed << setprecision(2) << fin << endl;
        }
};

int main() {
    int n;
    double b;
    int t;
    
    cin >> n;
    cin >> b;
    cin >> t;
    
    if (t == 1) {
        Savings s;
        s.setAccNo(n, b);
        s.displayAcc();
        s.cal();
        s.displaySa();
    }
    else if (t == 2) {
        Current c;
        c.setAccNo(n, b);
        c.displayAcc();
        c.cal();
        c.displayCu();
    }
    
    return 0;
}