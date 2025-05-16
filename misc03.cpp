#include <iostream>
#include <iomanip>
using namespace std;

// Function to calculate the determinant of a 3x3 matrix
double determinant(double A[3][3])
{
    return A[0][0] * (A[1][1] * A[2][2] - A[1][2] * A[2][1]) -
           A[0][1] * (A[1][0] * A[2][2] - A[1][2] * A[2][0]) +
           A[0][2] * (A[1][0] * A[2][1] - A[1][1] * A[2][0]);
}

// Function to calculate the inverse of a 3x3 matrix
bool inverseMatrix(double A[3][3], double inverse[3][3])
{
    double det = determinant(A);
    if (det == 0) {
        cout << "Matrix is singular, no unique solution exists." << endl;
        return false;
    }

    // Compute adjugate matrix
    double adj[3][3];
    adj[0][0] =  (A[1][1] * A[2][2] - A[1][2] * A[2][1]);
    adj[0][1] = -(A[0][1] * A[2][2] - A[0][2] * A[2][1]);
    adj[0][2] =  (A[0][1] * A[1][2] - A[0][2] * A[1][1]);

    adj[1][0] = -(A[1][0] * A[2][2] - A[1][2] * A[2][0]);
    adj[1][1] =  (A[0][0] * A[2][2] - A[0][2] * A[2][0]);
    adj[1][2] = -(A[0][0] * A[1][2] - A[0][2] * A[1][0]);

    adj[2][0] =  (A[1][0] * A[2][1] - A[1][1] * A[2][0]);
    adj[2][1] = -(A[0][0] * A[2][1] - A[0][1] * A[2][0]);
    adj[2][2] =  (A[0][0] * A[1][1] - A[0][1] * A[1][0]);

    // Compute inverse using adjugate and determinant
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            inverse[i][j] = adj[i][j] / det;

    return true;
}

// Function to multiply two matrices (3x3 and 3x1)
void multiplyMatrix(double A[3][3], double B[3], double result[3])
{
    for (int i = 0; i < 3; i++) {
        result[i] = 0;
        for (int j = 0; j < 3; j++) {
            result[i] += A[i][j] * B[j];
        }
    }
}

int main()
{
    double inverse[3][3], X[3];

    double A[3][3] = {
        {1, 1, 1},     // x + y + z = 25
        {5, 3, 2},     // 5x + 3y + 2z = 0
        {0, 1, -1}     // y - z = 6
    };

    // Define the constants on the right-hand side (d1, d2, d3)
    double B[3] = {25, 0, 6};

    // Compute inverse matrix
    if (!inverseMatrix(A, inverse)) {
        return 1; // Exit if inverse does not exist
    }

    // Multiply inverse(A) * B to find X
    multiplyMatrix(inverse, B, X);

    // Output the solution
    cout << fixed << setprecision(3);
    cout << "Solution: x = " << X[0] << ", y = " << X[1] << ", z = " << X[2] << endl;

    return 0;
}