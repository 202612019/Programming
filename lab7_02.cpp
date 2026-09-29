/*
--Add Two Numbers Using Operator Overloading--

Create a linked-list based class to represent a non-negative integer.
Digits are stored in reverse order.
Overload the + operator to add two number objects.
The overloaded + must handle carry between digits.
Overload the assignment operator = to copy one number object into another.
Implement a friend operator<< to display the resulting linked list.
Return the resulting number as a linked-list object.
Do not convert the complete linked lists into built-in integer types.
Input Format

The first linked list represents the first number.
The second linked list represents the second number.
Digits are stored in reverse order.
Each node contains one digit.
Create two number objects from the linked lists.
Use the overloaded + operator to obtain the result.
Constraints

Number of nodes in each linked list is in [1, 100].
0 <= Node.val <= 9.
Each list represents a number without leading zeros.
The number 0 is represented by [0].
Carry must be handled correctly.
The solution must work for numbers larger than the range of standard integer types.
Output Format

Output the resulting linked list.
Digits must remain in reverse order.
The output must represent the sum of the two input numbers.
Sample Input 0

l1 = [2,4,3]
l2 = [5,6,4]


Sample Output 0
[7,0,8]

*/

#include <iostream>
#include <list>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

class BigInt {
private:
    list<int> digits; 

public:
    BigInt() {}

    BigInt& operator=(const BigInt& other) {
        if (this != &other) {
            this->digits = other.digits;
        }
        return *this;
    }

    void append(int val) {
        digits.push_back(val);
    }

    BigInt operator+(const BigInt& other) const {
        BigInt result;
        
        auto p1 = this->digits.begin();
        auto p2 = other.digits.begin();
        int carry = 0;

        while (p1 != this->digits.end() || p2 != other.digits.end() || carry != 0) {
            int sum = carry;
            
            if (p1 != this->digits.end()) {
                sum += *p1;
                ++p1;
            }
            if (p2 != other.digits.end()) {
                sum += *p2;
                ++p2;
            }
            
            result.append(sum % 10);
            carry = sum / 10;
        }
        
        return result;
    }
    
    friend ostream& operator<<(ostream& os, const BigInt& num) {
        os << "[";
        auto it = num.digits.begin();
        while (it != num.digits.end()) {
            os << *it;
            auto next_it = it;
            ++next_it;
            
            if (next_it != num.digits.end()) {
                os << ",";
            }
            ++it;
        }
        os << "]";
        return os;
    }
};

int main() {

    string input = "";
    char c;
    while (cin >> c) {
        input += c;
    }

    BigInt l1, l2;
    int list_count = 0;
    bool in_list = false;

    for (char ch : input) {
        if (ch == '[') {
            in_list = true;
            list_count++;
        } else if (ch == ']') {
            in_list = false;
        } else if (in_list && isdigit(ch)) {
            if (list_count == 1) {
                l1.append(ch - '0');
            } else if (list_count == 2) {
                l2.append(ch - '0');
            }
        }
    }

    BigInt result = l1 + l2;
    cout << result << "\n";

    return 0;
}
