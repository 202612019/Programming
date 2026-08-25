#include <iostream>
#include <algorithm>
using namespace std;


int countSeqLength(long long arr[],int n){
    int seqLength = 1;
    sort(arr,arr+n);
    for(int i = 0; i < n-1;i++){
        if((arr[i+1]-arr[i]) >1){
            break;
        }
        if(arr[i+1] == arr[i]){
            continue;
        }
        if(arr[i+1] == arr[i]+1){
            seqLength++;
        }
    }
    return seqLength;
}

int main() {
    int n;
    cin>>n; 

    long long arr[n];

    for(int i = 0; i<n;i++){ 
        cin>>arr[i];  
    }

    cout<<countSeqLength(arr, n);
    
    return 0;
}