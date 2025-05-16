#include <iostream>
using namespace std;

// Function to compute determinant of a 3x3 matrix
double determinant(double a, double b, double c,
                   double d, double e, double f,
                   double g, double h, double i)
{
    return (a * (e * i - f * h)
          - b * (d * i - f * g)
          + c * (d * h - e * g));
}

int main()
{
    double a1, b1, c1, d1;
    double a2, b2, c2, d2;
    double b3, c3, d3;
    double x, y, z;

    // Input coefficients
    cout << "Enter coefficients for equation 1 (a1, b1, c1, d1): ";
    cin >> a1 >> b1 >> c1 >> d1;
    cout << "Enter coefficients for equation 2 (a2, b2, c2, d2): ";
    cin >> a2 >> b2 >> c2 >> d2;
    cout << "Enter coefficients for equation 3 (b3, c3, d3): ";
    cin >> b3 >> c3 >> d3;

    // Compute determinant of A
    double detA = determinant(a1, b1, c1,
                              a2, b2, c2,
                              0,  b3, c3);

    // Compute determinant of Ax (replace first column with d1, d2, d3)
    double detAx = determinant(d1, b1, c1,
                               d2, b2, c2,
                               d3, b3, c3);

    // Compute determinant of Ay (replace second column with d1, d2, d3)
    double detAy = determinant(a1, d1, c1,
                               a2, d2, c2,
                               0,  d3, c3);

    // Compute determinant of Az (replace third column with d1, d2, d3)
    double detAz = determinant(a1, b1, d1,
                               a2, b2, d2,
                               0,  b3, d3);

    // Check if system has a unique solution
    if (detA != 0)
    {
        x = detAx / detA;
        y = detAy / detA;
        z = detAz / detA;

        // Output results
        cout << "\nSolution of the system:\n";
        cout << "x = " << x << endl;
        cout << "y = " << y << endl;
        cout << "z = " << z << endl;
    }
    else
    {
        cout << "\nThe system has no unique solution (det(A) = 0)." << endl;
    }

    return 0;
}