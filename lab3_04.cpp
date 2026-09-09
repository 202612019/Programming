#include <iostream>
using namespace std;

int main() {
    
    int N;
    cin >> N;

    int* arr = new int[N];

    for (int i = 0; i < N; ++i) {
        cin >> *(arr + i);
    }


    int sum = 0;
    int min = *(arr + 0);
    int max = *(arr + 0);
    int count = 0;

    for (int i = 0; i < N; ++i) {
        int curr_val = *(arr + i);
        
        sum += curr_val;
        
        if (curr_val < min) {
            min = curr_val;
        }
        
        if (curr_val > max) {
            max = curr_val;
        }
        
        if (curr_val % 2 == 0) {
            count++;
        }
    }

    int* left = arr;
    int* right = arr + N - 1;
    
    while (left < right) {
        int temp = *left;
        *left = *right;
        *right = temp;
        left++;
        right--;
    }
    
    cout << "Sum: " << sum << "\n";
    cout << "Minimum: " << min << "\n";
    cout << "Maximum: " << max << "\n";
    cout << "Even Count: " << count << "\n";
    
    cout << "Reversed Array: ";
    for (int i = 0; i < N; ++i) {
        cout << *(arr + i) << (i == N - 1 ? "" : " ");
    }
    cout << "\n";

    delete[] arr;

    return 0;
}
