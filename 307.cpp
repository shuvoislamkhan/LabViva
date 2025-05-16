#include <iostream>
using namespace std;

int main()
{
    int rows, cols;

    // Getting matrix dimensions from user
    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;

    int matrix1[rows][cols], matrix2[rows][cols], sum[rows][cols];

    // Input for first matrix
    cout << "Enter elements of first matrix:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix1[i][j];
        }
    }

    // Input for second matrix
    cout << "Enter elements of second matrix:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix2[i][j];
        }
    }

    // Matrix addition
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    // Displaying the sum matrix
    cout << "Sum of matrices:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << sum[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}