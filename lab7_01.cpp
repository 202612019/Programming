/*
--Two Sum Object (Easy)--

Given an array of integers and a target value, find two different indices whose values add up to the target. Create a C++ class NumberArray to store the input array. Overload the assignment operator = to correctly copy one NumberArray object into another. Implement a friend function to perform the Two Sum operation. The friend function should return the two required indices. The same array element must not be used twice. Exactly one valid pair exists.

Input Format

4

2 7 11 15

9

Constraints

2 <= n <= 10^4

-10^9 <= nums[i] <= 10^9

-10^9 <= target <= 10^9

Exactly one valid pair exists. Do not use the same element twice.

Output Format

0 1

Sample Input 0

4
2 7 11 15
9
Sample Output 0

0 1
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class NumberArray {
private:
    vector<int> arr;

public:
    NumberArray(int n = 0) {
        arr.resize(n);
    }

    NumberArray& operator=(const NumberArray& other) {
        if (this != &other) {
            this->arr = other.arr;
        }
        return *this;
    }

    void readElements() {
        for (int i = 0; i < arr.size(); ++i) {
            cin >> arr[i];
        }
    }

    friend pair<int, int> findTwoSum(const NumberArray& nums, int target);
};

pair<int, int> findTwoSum(const NumberArray& nums, int target) {
    unordered_map<int, int> numMap;
    
    for (int i = 0; i < nums.arr.size(); ++i) {
        int complement = target - nums.arr[i];
        
        if (numMap.count(complement)) {
            return {numMap[complement], i};
        }
        
        numMap[nums.arr[i]] = i;
    }
    
    return {-1, -1}; 
}

int main() {
    int n;
    cin>>n;   
    
    NumberArray originalArray(n);
    originalArray.readElements(); 
    
    int target;
    cin >> target;
    
    NumberArray copiedArray;
    copiedArray = originalArray;

    pair<int, int> result = findTwoSum(copiedArray, target);
    
    cout << result.first << " " << result.second << "\n";
    
    return 0;
}