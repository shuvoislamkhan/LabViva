#include <iostream>
#include <cmath>

using namespace std;

// Function to calculate the value of f(x) = ax^4 + bx^3 + cx^2 + dx + e
double f(double x, double a, double b, double c, double d, double e) {
    return a * x * x * x * x + b * x * x * x + c * x * x + d * x + e;
}

// Function to calculate the derivative f'(x) = 4ax^3 + 3bx^2 + 2cx + d
double f_prime(double x, double a, double b, double c, double d) {
    return 4 * a * x * x * x + 3 * b * x * x + 2 * c * x + d;
}

// Newton-Raphson method to find roots
double newtonRaphson(double a, double b, double c, double d, double e, double initialGuess, int maxIterations = 1000, double tolerance = 1e-6) {
    double x = initialGuess;
    for (int i = 0; i < maxIterations; ++i) {
        double fx = f(x, a, b, c, d, e);
        double fx_prime = f_prime(x, a, b, c, d);

        if (fabs(fx) < tolerance) {
            return x; // Found root within tolerance
        }

        if (fx_prime == 0) {
            cout << "Derivative is zero, cannot continue." << endl;
            return x; // Derivative zero, avoid division by zero
        }

        x = x - fx / fx_prime; // Newton-Raphson iteration
    }

    cout << "Max iterations reached." << endl;
    return x;
}

int main() {
    double a, b, c, d, e;
    cout << "Enter coefficients a, b, c, d, e: ";
    cin >> a >> b >> c >> d >> e;

    double initialGuess;
    cout << "Enter initial guess: ";
    cin >> initialGuess;

    double root = newtonRaphson(a, b, c, d, e, initialGuess);
    cout << "Found root: " << root << endl;

    return 0;
}
