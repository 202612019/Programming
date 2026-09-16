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
