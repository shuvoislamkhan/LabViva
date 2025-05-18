#include <iostream>
#include <iomanip>
using namespace std;

int main() {

    double A[3][3], inverse[3][3], B[3], result[3];

    // Input the coefficients of the equations
    cout << "Enter coefficients a1, b1, c1, d1: ";
    cin >> A[0][0] >> A[0][1] >> A[0][2] >> B[0];

    cout << "Enter coefficients a2, b2, c2, d2: ";
    cin >> A[1][0] >> A[1][1] >> A[1][2] >> B[1];

    cout << "Enter coefficients b3, c3, d3: ";
    cin >> A[2][1] >> A[2][2] >> B[2];

    A[2][0] = 0;

    double det = A[0][0] * (A[1][1] * A[2][2] - A[1][2] * A[2][1]) -
                 A[0][1] * (A[1][0] * A[2][2] - A[1][2] * A[2][0]) +
                 A[0][2] * (A[1][0] * A[2][1] - A[1][1] * A[2][0]);

    if (det == 0) {
        cout << "Matrix is singular, no unique solution exists." << endl;
    }
    else {
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
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                inverse[i][j] = adj[i][j] / det;   
            }
        }
        for (int i = 0; i < 3; i++) {
            result[i] = 0;
            for (int j = 0; j < 3; j++) {
                result[i] += inverse[i][j] * B[j];
            }
        }
        // Output the solution
        cout << fixed << setprecision(3);
        cout << "Solution:\n";
        cout << "x = " << result[0] << "\n";
        cout << "y = " << result[1] << "\n";
        cout << "z = " << result[2] << endl;
    }
    return 0;
}