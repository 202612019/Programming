/*
--Object Copy Tracker--

Write a C++ program to demonstrate the execution of a constructor, copy constructor, and destructor.

Create a class Student with:

A data member name
A data member rollNo
A parameterized constructor
A copy constructor
A destructor
The program should create one original object and then create a second object by copying the first object.

Each constructor and destructor must print an appropriate message showing which object is being created or destroyed.

Add lot of comments in the code and print statements which might not be a need

Input Format

The first line contains the student's name.
The second line contains the student's roll number.
Constraints

1 ≤ rollNo ≤ 100000
1 ≤ length(name) ≤ 50
name contains only uppercase/lowercase English letters and spaces.
The student name will not contain leading or trailing spaces.
Exactly one original object and one copied object must be created.
The second object must be created using the copy constructor.
Output Format

Print messages showing:

Creation of the original object
Creation of the copied object using the copy constructor
Destruction of objects
Sample Input 0

Rahul
101
Sample Output 0

Constructor called for Student 101
Copy Constructor called for Student 101
Destructor called for Student 101
Destructor called for Student 101
*/

#include <iostream>
#include<string>
using namespace std;

class Student{
private:
    string name;
    int rollNo;
    
public:
    Student(string na, int no): name(na), rollNo(no){
        cout<<"Constructor called for Student "<<rollNo<<endl;
    }
    
    Student(const Student &source){
        this->name = source.name;
        this->rollNo = source.rollNo;
        cout<<"Copy Constructor called for Student "<<rollNo<<endl;
    }
    
    ~Student(){
        cout<<"Destructor called for Student "<<rollNo<<endl;
    }
    
    void displayStudentDetails() const {
        cout << "[DEBUG INFO] Name: " << name << " | Roll Number: " << rollNo << endl;
    }
    
};

int main() {
    
    string name;
    
    int rollno;
    getline(cin, name);
    cin>>rollno;
    
    Student s1(name, rollno);
    Student s2 = s1;
    
    return 0;
}