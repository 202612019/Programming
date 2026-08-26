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
