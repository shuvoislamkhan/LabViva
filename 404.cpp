#include <iostream>
#include <cmath>
using namespace std;

// Function to be integrated
double f(double x) {
    return 1.0 / (1.0 + x * x); // Example: f(x) = 1 / (1 + x^2)
}

// Trapezoidal Rule Implementation
double trapezoidalRule(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.5 * (f(a) + f(b)); // Add endpoints once

    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        sum += f(x);
    }

    return sum * h;
}

int main() {
    double a, b;
    int n;

    // Input from user
    cout << "Enter lower limit a: ";
    cin >> a;
    cout << "Enter upper limit b: ";
    cin >> b;
    cout << "Enter number of subintervals n: ";
    cin >> n;

    // Validate input
    if (n <= 0 || b <= a) {
        cout << "Invalid input. Ensure that n > 0 and b > a." << endl;
        return 1;
    }

    // Compute the integral
    double result = trapezoidalRule(a, b, n);

    // Output the result
    cout << "Approximate value of the integral of 1 / (1 + x^2) from "
         << a << " to " << b << " using the trapezoidal rule is: "
         << result << endl;

    return 0;
}