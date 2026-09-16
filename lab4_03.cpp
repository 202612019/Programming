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