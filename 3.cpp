#include <iostream>
#include <cmath>

int main() {
    double a, b, c;
    std::cout << "Enter a, b, c: ";
    std::cin >> a >> b >> c;

    double d = b * b - 4 * a * c; // Discriminant

    if (d > 0) {
        double r1 = (-b + sqrt(d)) / (2 * a);
        double r2 = (-b - sqrt(d)) / (2 * a);
        std::cout << "Roots: " << r1 << " , " << r2 << std::endl;
    }
    else if (d == 0) {
        double r = -b / (2 * a);
        std::cout << "One root: " << r << std::endl;
    }
    else {
        std::cout << "Complex roots" << std::endl;
    }

    return 0;
}

