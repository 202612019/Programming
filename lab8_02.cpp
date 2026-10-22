/*
--The Smart Payment Gateway--

You are developing a payment gateway that supports three payment methods: UPI, Card, and Wallet.

Each payment method processes transactions differently. Your task is to implement a common abstract class named Payment and derive three classes from it:

UPIPayment
CardPayment
WalletPayment
The base class must declare a pure virtual function named processPayment(double amount). Each derived class must override this function and display the appropriate payment method and transaction amount.

The program must also demonstrate the difference between early binding and late binding.

The base class must contain a non-virtual function named paymentType() that prints Payment: General. Each derived class must define a function with the same name that prints its specific payment type. When paymentType() is called through a base-class pointer, the base-class implementation must execute because the function is non-virtual.

In contrast, processPayment() must be virtual, so the appropriate derived-class implementation executes when called through a base-class pointer.

Finally, implement a virtual destructor in the base class and a destructor in every derived class. The program must delete payment objects through base-class pointers after processing all transactions.

Payment processing rules

UPI payments must print UPI Payment: amount.
Card payments must print Card Payment: amount.
Wallet payments must print Wallet Payment: amount.
Replace amount with the transaction amount formatted to exactly two decimal places.

For each transaction, print the result of paymentType() first, followed by the result of processPayment().

After processing all transactions, delete the payment objects in their input order. Print the corresponding derived-class destructor message followed by the base-class destructor message.

Input Format

The first line contains an integer (N), representing the number of payment transactions.
Each of the next (N) lines contains a payment type and a transaction amount.
The payment type is one of:
U — UPI payment
C — Card payment
W — Wallet payment
The amount is a positive decimal number.
Constraints

1 <= N <= 100
0 < amount <= 10^7

Payment types will only be U, C, or W.

Each transaction contains exactly one payment type and one amount.
Print every transaction amount with exactly two digits after the decimal point.
Use a pure virtual function in the base class.
Access and delete all payment objects through base-class pointers.
The base-class destructor must be virtual.
Process and destroy transactions in their input order.
Output Format

For each transaction, print two lines:

Payment: General
The payment result in the format UPI Payment: X.XX, Card Payment: X.XX, or Wallet Payment: X.XX, depending on the transaction type.
After processing all transactions, print two destructor messages for each transaction, in input order:

UPI destructor followed by Payment destructor
Card destructor followed by Payment destructor
Wallet destructor followed by Payment destructor
Each message must appear on a separate line.

Sample Input 0

3
U 500
C 1250.50
W 250
Sample Output 0

Payment: General
UPI Payment: 500.00
Payment: General
Card Payment: 1250.50
Payment: General
Wallet Payment: 250.00
UPI destructor
Payment destructor
Card destructor
Payment destructor
Wallet destructor
Payment destructor
Explanation 0

The program creates three payment objects and stores their addresses in base-class pointers.

The UPI transaction processes an amount of 500.00.
The card transaction processes an amount of 1250.50.
The wallet transaction processes an amount of 250.00.
The non-virtual paymentType() function demonstrates early binding, so Payment: General is printed for every transaction. The virtual processPayment() function demonstrates late binding, so the appropriate payment method is selected at runtime.

When the objects are deleted, the derived destructor executes first, followed by the base-class destructor.
*/

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class Payment {
    public:
        virtual ~Payment() {
            cout << "Payment destructor\n";
        }

        virtual void processPayment() const = 0;

        void paymentType() const {
            cout << "Payment: General\n";
        }
};

class UPIPayment : public Payment {
    private:
        double amount;
    public:
        UPIPayment(double amt) : amount(amt) {}

        ~UPIPayment() override {
            cout << "UPI destructor\n";
        }

        void processPayment() const override {
            cout << "UPI Payment: " << fixed << setprecision(2) << amount << "\n";
        }

        void paymentType() const {
            cout << "Payment: UPI\n";
        }
};

class CardPayment : public Payment {
    private:
        double amount;
    public:
        CardPayment(double amt) : amount(amt) {}

        ~CardPayment() override {
            cout << "Card destructor\n";
        }

        void processPayment() const override {
            cout << "Card Payment: " << fixed << setprecision(2) << amount << "\n";
        }

        void paymentType() const {
            cout << "Payment: Card\n";
        }
};

class WalletPayment : public Payment {
    private:
        double amount;
    public:
        WalletPayment(double amt) : amount(amt) {}

        ~WalletPayment() override {
            cout << "Wallet destructor\n";
        }

        void processPayment() const override {
            cout << "Wallet Payment: " << fixed << setprecision(2) << amount << "\n";
        }

        void paymentType() const {
            cout << "Payment: Wallet\n";
        }
};

int main() {
    int n;
    cin >> n;

    vector<Payment*> payments;

    for (int i = 0; i < n; ++i) {
        char type;
        double amount;
        cin >> type >> amount;
        
        if (type == 'U') {
            payments.push_back(new UPIPayment(amount));
        } else if (type == 'C') {
            payments.push_back(new CardPayment(amount));
        } else if (type == 'W') {
            payments.push_back(new WalletPayment(amount));
        }
    }

    for (Payment* pay : payments) {
        pay->paymentType();
        pay->processPayment();
    }

    for (Payment* pay : payments) {
        delete pay; 
    }

    return 0;
}
