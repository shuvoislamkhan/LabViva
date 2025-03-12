#include <iostream>
#include <cmath>

// Function to find one real root (trial method)
double findRealRoot(double a, double b, double c, double d) {
    for (double x = -100; x <= 100; x += 0.01) { // Try values from -100 to 100
        double f = a*x*x*x + b*x*x + c*x + d;
        if (fabs(f) < 1e-3) return x; // Found a root
    }
    return 0; // Default if no root found (should not happen)
}

int main() {
    double a, b, c, d;
    std::cout << "Enter coefficients a, b, c, d: ";
    std::cin >> a >> b >> c >> d;

    if (a == 0) {
        std::cout << "Not a cubic equation!" << std::endl;
        return 0;
    }

    double r1 = findRealRoot(a, b, c, d);
    std::cout << "One real root: " << r1 << std::endl;

    // Reduce cubic equation to quadratic
    double newB = b + a * r1;
    double newC = c + newB * r1;

    // Solve quadratic equation
    double D = newB * newB - 4 * a * newC;

    if (D > 0) {
        double r2 = (-newB + sqrt(D)) / (2 * a);
        double r3 = (-newB - sqrt(D)) / (2 * a);
        std::cout << "Other roots: " << r2 << " , " << r3 << std::endl;
    }
    else if (D == 0) {
        double r2 = -newB / (2 * a);
        std::cout << "Other root: " << r2 << std::endl;
    }
    else {
        std::cout << "Other roots are complex!" << std::endl;
    }

    return 0;
}
