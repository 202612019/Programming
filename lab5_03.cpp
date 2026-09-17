/*
--Demonstrating Shallow Copy--

Create a class Array that dynamically allocates memory for a single integer using a pointer.

The class should contain:

int *value;

Implement:

Parameterized constructor
Copy constructor
Destructor
display() function
Initially create one object and then create another object using the copy constructor.

Modify the value through the second object.

Demonstrate that both objects refer to the same dynamically allocated memory when a shallow copy is performed.

Input Format

The first line contains the initial integer value.

The second line contains the new value assigned through the copied object.

Constraints

-10^6 ≤ initialValue ≤ 10^6
-10^6 ≤ newValue ≤ 10^6
value must be stored using a dynamically allocated int.
The class must contain an int* data member.
The copy constructor must perform a shallow copy.
Both objects must initially contain the same value.
After modifying the copied object, the original object's value must also change.
The dynamically allocated memory must be released using a destructor.
Students should not use STL containers or smart pointers for this problem.
Output Format

Print the values before and after modifying the copied object in the following format:

Original value: <initialValue>
Copied value: <initialValue>

After modifying copied object:
Original value: <newValue>
Copied value: <newValue>
Sample Input 0

10
50
Sample Output 0

Original value: 10
Copied value: 10

After modifying copied object:
Original value: 50
Copied value: 50
*/

#include <iostream>
using namespace std;

class Array {
private:
    int *value;

public:
    Array(int v) {
        value = new int(v);
    }

    Array(const Array &source) {
        value = source.value;
    }

    ~Array() {
    }

    void display() {
        cout << *value << endl;
    }

    void setValue(int v) {
        *value = v;
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
    a.display();

    cout << "Copied value: ";
    a1.display();

    a1.setValue(b);

    cout << endl;
    cout << "After modifying copied object:" << endl;

    cout << "Original value: ";
    a.display();

    cout << "Copied value: ";
    a1.display();

    return 0;
}