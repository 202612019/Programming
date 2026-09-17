/*
--Implementing Deep Copy--

Create a class Array that dynamically allocates memory for an integer using a pointer.

The class should contain:

int *value;

Implement:

Parameterized constructor
Copy constructor
Destructor
setValue()
getValue()
The copy constructor must perform a deep copy.

When an object is copied:

A new memory location must be allocated. The value from the original object must be copied into the new memory. Modifying the copied object must not affect the original object.

Input Format

The first line contains the original value.

The second line contains the value to assign to the copied object.

Constraints

The program must correctly release dynamically allocated memory using the destructor.

Concept tested:

Deep copy, dynamic memory allocation, copy constructor, destructor, ownership.

Output Format

Original value: 100
Copied value: 100

After modifying copied object:
Original value: 100
Copied value: 500
Sample Input 0

10
50
Sample Output 0

Original value: 10
Copied value: 10

After modifying copied object:
Original value: 10
Copied value: 50
*/

#include <iostream>
using namespace std;

class Array{
    
private:
    int *value;
    
public:
    Array(int v) {
        value = new int(v);
    }

    Array(const Array &source) {
        value = new int ;
        *value = *source.value;
    }

    ~Array() {
        delete value;
    }

    void display() {
        cout << *value << endl;
    }

    void setValue(int v) {
        *value = v;
    }
    
    void getValue(){
        cout << *value << endl;
    }
    
};

int main() {
    
    int n;
    cin >> n;

    int b;
    cin >> b;

    Array a(n);
    Array a1(a);

    cout << "Original value: ";
    a.getValue();

    cout << "Copied value: ";
    a1.getValue();

    a1.setValue(b);

    cout << endl;
    cout << "After modifying copied object:" << endl;

    cout << "Original value: ";
    a.getValue();

    cout << "Copied value: ";
    a1.getValue();
    
    return 0;
}
