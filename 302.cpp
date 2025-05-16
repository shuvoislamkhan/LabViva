#include <iostream>
using namespace std;
int main() {
    // Declare variables
    double x, y, z;
    // Solve for z
    z = 113.0 / 5.0; // z = 22.6
    // Solve for y
    y = z + 6; // y = 28.6
    // Solve for x
    x = 19 - 2 * z; // x = -26.2
    // Output results
    cout << "Solution of the system:" << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "z = " << z << endl;
    return 0;
}