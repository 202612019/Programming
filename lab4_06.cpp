/*
--Bank Account Lifecycle--

Create a class BankAccount that represents a bank account.

Each account must have a unique account number assigned when the object is created.

The class must contain:

A constructor to initialize the account number and balance.
A destructor that prints a message when the account object is destroyed.
A member function deposit() to add money to the balance.
A member function display() to print the account details.
The constructor must print:

Account X Created

The destructor must print:

Account X Destroyed

where X is the account number.

Inside the main() function, create N BankAccount objects using a loop.

After creating all objects, deposit the given amount into each account and display the final balance.

When the program ends, the destructors must execute automatically in the reverse order in which the objects were created.

Input Format

The first line contains an integer N, representing the number of bank accounts.

The second line contains N integers representing the initial deposit amount for each account.

Constraints

1 ≤ N ≤ 10
0 ≤ deposit ≤ 10000
Output Format

For every account, first print its creation message.

Then print the final balance of every account.

Finally, print the destruction messages in reverse order.

Sample Input 0

3 
1000 2500 5000
Sample Output 0

Account 1 Created 
Account 2 Created 
Account 3 Created 
Account 1 Balance: 1000 
Account 2 Balance: 2500 
Account 3 Balance: 5000 
Account 3 Destroyed 
Account 2 Destroyed 
Account 1 Destroyed
*/

#include <iostream>
#include <vector>

using namespace std;

class BankAccount {
private:
    int accountNumber;
    int balance;

public:
    BankAccount(int accNum, int initialBalance = 0) 
        : accountNumber(accNum), balance(initialBalance) {
        cout << "Account " << accountNumber << " Created\n";
    }

    ~BankAccount() {
        cout << "Account " << accountNumber << " Destroyed\n";
    }

    void deposit(int amount) {
        balance += amount;
    }

    void display() const {
        cout << "Account " << accountNumber << " Balance: " << balance << "\n";
    }
};

int main() {
    int n;
    if (!(cin >> n)) return 0;

    vector<int> depositAmounts(n);
    for (int i = 0; i < n; ++i) {
        cin >> depositAmounts[i];
    }

    BankAccount** accounts = new BankAccount*[n];

    for (int i = 0; i < n; ++i) {
        accounts[i] = new BankAccount(i + 1);
    }

    for (int i = 0; i < n; ++i) {
        accounts[i]->deposit(depositAmounts[i]);
        accounts[i]->display();
    }

    for (int i = n - 1; i >= 0; --i) {
        delete accounts[i];
    }

    delete[] accounts;

    return 0;
}
