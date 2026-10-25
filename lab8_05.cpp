/*
--The Notification Dispatcher--

Create a base class Notification and three derived classes: EmailNotification, SMSNotification, and PushNotification.

The base class must have a virtual function send() that each derived class overrides to print its notification message.

Use base-class pointers to call send() for each notification type. The program must demonstrate runtime polymorphism.

The base class must also have a virtual destructor, and each derived class must define its own destructor.

Input Format

The first line contains an integer (N), the number of notifications.

Each of the next (N) lines contains one character: - E — Email notification - S — SMS notification - P — Push notification

Constraints

1 <= N <= 100
Notification type must be E, S, or P.
All objects must be accessed and deleted through base-class pointers.
Output Format

For each notification, print the corresponding message:

Email: Sending Email
SMS: Sending SMS
Push: Sending Push Notification
After sending all notifications, print destructor messages in input order. Each derived destructor must print its class-specific message, followed by Notification destructor.

Sample Input 0

3
E
S
P
Sample Output 0

Sending Email
Sending SMS
Sending Push Notification
EmailNotification destructor
Notification destructor
SMSNotification destructor
Notification destructor
PushNotification destructor
Notification destructor
*/

#include <vector>
#include <iostream>

using namespace std;

class Notification {
    public:
        virtual ~Notification() {
            cout << "Notification destructor\n";
        }
        
        virtual void send() const = 0;
};

class EmailNotification : public Notification {
    public:
        void send() const override {
            cout << "Sending Email\n";
        }
        
        ~EmailNotification() override {
            cout << "EmailNotification destructor\n";
        }
};

class SMSNotification : public Notification {
    public:
        void send() const override {
            cout << "Sending SMS\n";
        }
        
        ~SMSNotification() override {
            cout << "SMSNotification destructor\n";
        }
};

class PushNotification : public Notification {
    public:
        void send() const override {
            cout << "Sending Push Notification\n";
        }
        
        ~PushNotification() override {
            cout << "PushNotification destructor\n";
        }
};

int main() {
    int n;
    cin >> n;

    vector<Notification*> notifications;
    for (int i = 0; i < n; ++i) {
        char type;
        cin >> type;
        
        if (type == 'E') {
            notifications.push_back(new EmailNotification());
        } else if (type == 'S') {
            notifications.push_back(new SMSNotification());
        } else if (type == 'P') {
            notifications.push_back(new PushNotification());
        }
    }

    for (Notification* nt : notifications) {
        nt->send();
    }

    for (Notification* nt : notifications) {
        delete nt; 
    }
    
    return 0;
}