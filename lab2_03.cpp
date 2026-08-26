#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


void arrInput(int arr[],int n){
    for(int i = 0; i<n;i++){
        cin>>arr[i];
    }
}
void printArr(vector<int> result,int n){
    cout<<(result.size()/3);
    for(int i = 0; i<n;i++){
        
        if(i % 3 == 0){
            cout<<endl;
        }
        cout<<result[i]<<" ";
    }
}
    
vector<int> threeSum(int arr[],int n){
    vector<int> arr3Sum;
    sort(arr,arr+n);

    for(int i =0; i<n-2; i++){
        if(i>0 && arr[i] == arr[i-1]){
            continue;
        }
        int left = i+1;
        int right = n-1;
        while(left<right){
            int sum = arr[i] + arr[left] + arr[right];
            if(sum == 0){
                arr3Sum.push_back(arr[i]);
                arr3Sum.push_back(arr[left]);
                arr3Sum.push_back(arr[right]);
                left++;
                right--;
                while(left<right && arr[left] == arr[left-1]){
                    left++;
                }
                while(left<right && arr[right]==arr[right-1]){
                    right++;
                }
            }else if(sum < 0){
                left++;
            }else{
                right--;
            }
        }
    }
    return arr3Sum;
}
int main() {
    int n;
    cin>>n;
    if(n>=3 && n<=3000){
        int arr[n];

        arrInput(arr, n);
    
        vector<int> result =threeSum(arr,n); 
        printArr(result,result.size());
    }
    
    return 0;
}