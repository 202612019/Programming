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