/*
--Merge K Sorted Lists Using Operator Overloading--

Create a ListNode class for linked-list nodes.
Each input linked list is sorted in ascending order.
Merge all k linked lists into one sorted linked list.
Overload < for comparing node objects.
Use the overloaded comparison with a priority queue/min-heap.
Overload = for copying list-wrapper objects correctly.
Implement friend operator<< to display the final linked list.
Return the merged list in ascending order.
Handle empty lists and an empty collection of lists.
Input Format

The first value represents the number of linked lists k.
Each list contains integers in ascending order.
Lists may be empty.
All nodes from all lists must be merged into one list.
The resulting list must preserve ascending order.
Constraints

0 <= k <= 10^4

0 <= lists[i].length <= 500

-10^4 <= lists[i][j] <= 10^4

Every individual list is sorted in ascending order.

The total number of nodes does not exceed 10^4.

Empty lists must be handled correctly.

The comparison operator must work correctly with the priority queue.

Output Format

Output one sorted linked list.
Preserve duplicate values.
If all lists are empty, output [].
The result must contain every node from every input list exactly once

Sample Input 0
lists = [[1,4,5],[1,3,4],[2,6]]

Sample Output 0
[1,1,2,3,4,4,5,6]

*/

#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

struct ListNode {
    int val;
    ListNode* next = nullptr;
    ListNode(int x) : val(x) {}
    
    bool operator<(const ListNode& other) const { return val > other.val; } 
};

struct Compare {
    bool operator()(ListNode* a, ListNode* b) { return *a < *b; }
};

class LinkedList {
public:
    ListNode *head = nullptr, *tail = nullptr;
    
    LinkedList() {}
    LinkedList(const LinkedList& o) { *this = o; }
    
    LinkedList& operator=(const LinkedList& o) {
        if (this == &o) return *this;
        head = tail = nullptr; 
        for (ListNode* c = o.head; c; c = c->next) append(c->val);
        return *this;
    }
    
    void append(int v) {
        ListNode* n = new ListNode(v);
        if (!head) head = tail = n;
        else tail = tail->next = n;
    }
    
    friend ostream& operator<<(ostream& os, const LinkedList& l) {
        os << "[";
        for (ListNode* c = l.head; c; c = c->next) os << c->val << (c->next ? "," : "");
        return os << "]";
    }
};

int main() {
    string s; char c; 
    while (cin >> c) s += c;

    vector<LinkedList> lists;
    LinkedList curr;
    string num;
    
    for (size_t i = 0; i < s.size(); i++) {
        if (isdigit(s[i]) || s[i] == '-') {
            num += s[i];
        } else {
            if (!num.empty()) {
                curr.append(stoi(num));
                num = "";
            }
            if (s[i] == ']' && curr.head) {
                lists.push_back(curr);
                curr.head = curr.tail = nullptr;
            }
        }
    }

    priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
    
    for (auto& l : lists) {
        if (l.head) pq.push(l.head);
    }

    LinkedList res;
    
    while (!pq.empty()) {
        ListNode* minNode = pq.top(); 
        pq.pop();
        
        res.append(minNode->val);
        if (minNode->next) pq.push(minNode->next);
    }

    cout << res << "\n";
    return 0;
}