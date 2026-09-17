/*
--Best Time to Buy and Sell Stock--

You are given an array prices, where prices[i] represents the price of a stock on the i-th day.

You may choose one day to buy one stock and choose a different day in the future to sell that stock.

Your goal is to maximize the profit from this transaction.

The profit is calculated as:

Profit = Selling Price - Buying Price

Return the maximum profit that can be achieved.

If no profitable transaction is possible, return 0.

You must buy before you sell. You cannot sell the stock before buying it.

Example 1: Input

6

7 1 5 3 6 4

Output

5

Explanation:

Buy the stock on day 2 at price 1 and sell it on day 5 at price 6.

Maximum profit:

6 - 1 = 5

Example 2

Input

5

7 6 4 3 1

Output

0

Explanation:

The stock price continuously decreases, so no profitable transaction is possible. Therefore, the maximum profit is 0.

Input Format

The first line contains an integer N, representing the number of days.
The second line contains N space-separated integers representing the stock price on each day.
Constraints

1 <= N <= 10^5
0 <= prices[i] <= 10^4
Output Format

Print a single integer representing the maximum profit that can be achieved by buying the stock on one day and selling it on a later day.

Sample Input 0

6
7 1 5 3 6 4
Sample Output 0

5
*/

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
