/*
--Matrix Transpose Using Classes--

You are given two integers R and C representing the number of rows and columns of a matrix.

Create a class Matrix that dynamically allocates a 2D array using pointers. The class must:

Allocate memory using a constructor
Free all allocated memory using a destructor
Provide a function transpose() to transpose the matrix
Provide a function print() to display the matrix After reading the matrix, transpose it and print the resulting matrix.
Input Format

The first line contains two integers R and C

The next R lines contain C space-separated integers representing the matrix elements

R C a11 a12 ... a1C a21 a22 ... a2C ... aR1 aR2 ... aRC

Constraints

1 <= R, C <= 1000 -10^9 <= matrix[i][j] <= 10^9

Output Format

Print the transposed matrix of size C x R.

Each row of the output should contain space-separated integers.

Sample Input 0

2 3
1 2 3
4 5 6
Sample Output 0

1 4
2 5
3 6
*/

#include <iostream>
using namespace std;

class Matrix{
    
private:
    int rows;
    int cols;
    int** data;
    
public:
    
    Matrix(int r, int c) {
        rows = r;
        cols = c;
        data = new int*[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new int[cols];
        }
    }
    
    ~Matrix(){
        for (int i = 0; i < rows; i++) {
            delete[] data[i];
        }
        delete[] data;
    }
    
    void setElement(int i, int j, int value) {
        data[i][j] = value;
    }
    
    void transpose() {
        int** newData = new int*[cols];
        for (int i = 0; i < cols; i++) {
            newData[i] = new int[rows];
            for (int j = 0; j < rows; j++) {
                newData[i][j] = data[j][i];
            }
        }

        for (int i = 0; i < rows; i++) {
            delete[] data[i];
        }
        delete[] data;

        data = newData;
        swap(rows, cols);
    }
    
    void print() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << data[i][j];
                if (j < cols - 1) {
                    cout << " ";
                }
            }
            cout << "\n";
        }
    }
    
};

int main() {
    
    int r, c;
    cin >> r >> c;
    
    Matrix mat(r, c);
    
    for (int i = 0; i < r; i++){
        for(int j= 0; j < c; j++){
            int val;
            cin >> val;
            mat.setElement(i, j, val);
        }
    }
    
    mat.transpose();
    mat.print();
       
    return 0;
}