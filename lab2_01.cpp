#include <iostream>
using namespace std;

int timeToBuy(int arr[],int n){
    int p =0;
    for(int i = 0;i<(n-1);i++){
        int bp=i,sp=bp+1;
        while(arr[bp]>arr[sp]){
            bp++;
            sp++;
        }
        while(sp<n){   
            p = max((arr[sp]-arr[bp]),p);
            sp++;
        }   
    }
 return p;   
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    
    for(int i = 0; i<n;i++){ 
        cin>>arr[i];  
    }
    
    int profit = timeToBuy(arr, n);
    cout<<profit;

    return 0;
}
