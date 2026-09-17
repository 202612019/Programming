/*
--Copy Constructor in Function Calls--

Create a class Box containing an integer length.

Implement:

A parameterized constructor
A copy constructor
A destructor
A function display()
Create an object of Box in main() and pass it to a function by value.

The function should display the copied object's value.

Students must observe that passing an object by value can invoke the copy constructor.

Add lot of comments in the code and print statements which might not be a need

Input Format

A single integer representing the length of the box.

Constraints

1 ≤ length ≤ 10^6
length is an integer.
The Box object must be created using the parameterized constructor.
The object must be passed to the function by value.
Passing the object by value should invoke the copy constructor.
The copied object's length must remain unchanged when the original object's value is not modified.
Output Format

Display:

Message when the original object is created
Message when the copy constructor is called
Length of the copied object
Destructor messages
Sample Input 0

25
Sample Output 0

Constructor called
Copy Constructor called
Length = 25
Destructor called
Destructor called
*/

#include <iostream>
using namespace std;

class Box{
private:
    int length;
public:
    Box(int l):length(l){
        cout<<"Constructor called"<<endl;
    }
    
    Box(const Box &source){
        cout<<"Copy Constructor called"<<endl;
    }
    
    ~Box(){
        cout<<"Destructor called"<<endl;
    }
    
    void display(){
        cout<<"Length = "<<length<<endl;
    }

};

int main() {
      int n;
      cin>>n;
      
      Box b(n);
      Box b1 = b;
      b.display();
      
    return 0;
}