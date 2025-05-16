#include <iostream>
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
    std::cout << "Solution of the system:" << std::endl;
    std::cout << "x = " << x << std::endl;
    std::cout << "y = " << y << std::endl;
    std::cout << "z = " << z << std::endl;
    return 0;
}