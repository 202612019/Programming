/*
--Constructor & Destructor Order--

Create a class Counter that demonstrates the order in which constructors and destructors are executed. - The constructor should print: Object Created

The destructor should print: Object Destroyed where is the unique number assigned to each object.
Program Requirements - The first line of input contains an integer n, representing the number of objects to create. - Inside a function createCounter(int n), create n objects of class Counter using a loop. - Assign each object an ID starting from 1 up to n. - Observe that destructors are called in the reverse order of object creation when the function scope ends.

Input Format

One line input of an integer value.

n

Constraints

1 ≤ n ≤ 10^10

Output Format

First print constructor messages in order of creation.
Then print destructor messages in reverse order.
example:

Object 1 Created
Object 1 Destroyed
Sample Input 0

2
Sample Output 0

Object 1 Created
Object 2 Created
Object 2 Destroyed
Object 1 Destroyed
Explanation 0

Here input is 2, so you should create 2 object, and then print "Object n Created" after creating the object. And then call the deconstructos (Make sure that the destructors are called in reverse order of that of object creation, thus Object 2 is destroied first and then Object 1 is destroyed).
*/

#include <iostream>
using namespace std;

class Counter {
private:
    int id;
public:
    Counter(int unique_id) : id(unique_id) {
        cout << "Object " << id << " Created"<<endl;
    }
    ~Counter() {
        cout << "Object " << id << " Destroyed"<<endl;
    }
};

void buildCounters(int current, int n) {
    if (current > n) return;

    Counter c(current);
    buildCounters(current + 1, n);
    
}

void createCounter(int n) {
    buildCounters(1, n);
}

int main() {
    int n;
    cin >> n;
    createCounter(n);
    return 0;
}