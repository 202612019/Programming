/*
--Constructor and Destructor Order in Inheritance--

Create a C++ program using multilevel inheritance with the following class hierarchy:
Device
Computer inherits from Device
Laptop inherits from Computer
Each class must contain a constructor and a destructor.
The constructors must print the following messages:
Device Constructor
Computer Constructor
Laptop Constructor
The destructors must print the following messages:
Laptop Destructor
Computer Destructor
Device Destructor
The program should create an object of the Laptop class.
The program must also read and display a device ID.
The output must demonstrate the correct order of constructor and destructor invocation.
When the Laptop object is created, the base class constructor is called first, followed by the derived class constructors.
When the Laptop object is destroyed, the derived class destructor is called first, followed by the base class destructors.
Do not use polymorphism or virtual functions.
Input Format

The first line contains a string representing the device name.
The second line contains an integer representing the device ID.
Constraints

1 ≤ deviceID ≤ 100000
The device name contains only English letters.
Output Format

Print the following messages in the exact order:
Device Constructor
Computer Constructor
Laptop Constructor
Device ID:
Laptop Destructor
Computer Destructor
Device Destructor

Sample Input 0:-

HP
500

Sample Output 0:-

Device Constructor
Computer Constructor
Laptop Constructor
Device ID: 500
Laptop Destructor
Computer Destructor
Device Destructor

Sample Input 1:-
Lenovo
99999

Sample Output 1:-

Device Constructor
Computer Constructor
Laptop Constructor
Device ID: 99999
Laptop Destructor
Computer Destructor
Device Destructor
*/


#include <iostream>
#include <string>
using namespace std;

class Device{
    public:
        int id;
        Device(){
            cout<<"Device Constructor"<<endl;
        }
        ~Device(){
            cout<<"Device Destructor"<<endl;
        }
        void setid(int i){
            id = i;
        }
        void display(){
            cout<<"Device ID: "<<id<<endl;
        }
};

class Computer : public Device{
    public:
        Computer(){
            cout<<"Computer Constructor"<<endl;
        }
        ~Computer(){
            cout<<"Computer Destructor"<<endl;
        }
};

class Laptop : public Computer{
    public:
        Laptop(){
            cout<<"Laptop Constructor"<<endl;
        }
        ~Laptop(){
            cout<<"Laptop Destructor"<<endl;
        }
};

int main() {
    string n;
    cin>>n;
    int i;
    cin>>i;    
    Laptop l;
    l.setid(i);
    l.display();
    return 0;
}
