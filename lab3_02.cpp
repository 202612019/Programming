/*
--Persistent Counter--

Write a function counter() that keeps track of the number of times it has been called.

Inside the counter() function, declare a local static variable:

static int count = 0;

Every time counter() is called, increase count by 1 and print its value.

You must use a local static variable.

Do not use a global variable.

Input Format

The first line contains an integer N representing the number of times counter() should be called.

Constraints

1 <= N <= 100

Output Format

Print N lines.

Each line should contain the current value of the counter.

Sample Input 0

5
Sample Output 0

1
2
3
4
5
Sample Input 1

3
Sample Output 1

1
2
3
*/

#include <iostream>
using namespace std;

int Counter(int n){
    static int count = 0;
    for(int i = 1; i <= n; i++){
        cout<< i<<endl;
        count++;
    }
    return count;
}

int main() {
    
    int n;
    cin>>n;
    
    Counter(n);
    
    return 0;
}
