#include <iostream>
#include <algorithm>
using namespace std;

int countSeqLength(int arr[],int n){
    int count = 1;
    sort(arr,arr+n);
    for(int i = 0; i < n-1;i++){
        if((arr[i+1]-arr[i]) >1){
            break;
        }
        if(arr[i+1] == arr[i]){
            continue;
        }
        if(arr[i+1] == arr[i]+1){
            count++;
        }
    }
    return count;
}

int main() {
    int n;
    cin>>n; 

    int arr[n];

    for(int i = 0; i<n;i++){ 
        cin>>arr[i];  
    }

    cout<<countSeqLength(arr, n);
    
    return 0;
}