#include <iostream>
using namespace std;

int get_base(int n, int base) {
    if (n < 10) {
        return base;
    }
    return get_base(n / 10, base * 10);
}

int  countDigitOne(int n) {
    if (n <= 0) return 0;
    if (n < 10) return 1;

    int base = get_base(n, 1);
    int  m = n / base;
    int r = n % base;

    int o_base = countDigitOne(base - 1);
    
    if (m == 1) {
        return o_base + (r + 1) + countDigitOne(r);
    } 
    else {
        return m * o_base + base + countDigitOne(r);
    }
}

int main() {
    

    int n;
    cin >> n;
    cout << countDigitOne(n) << "\n";

    return 0;
}
