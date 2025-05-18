#include <iostream>
#include <cmath>
using namespace std;

// Function to be integrated
double f(double x) {
    return 1.0 / (1.0 + x * x); // Example function: 1 / (1 + x^2)
}

int main() {
    double a, b;
    int n;

    // User input
    cout << "Enter lower limit a: ";
    cin >> a;
    cout << "Enter upper limit b: ";
    cin >> b;
    cout << "Enter number of subintervals n (even number preferred): ";
    cin >> n;

    // Validate input
    if (b <= a || n <= 0) {
        cout << "Invalid input. Ensure that b > a and n > 0." << endl;
        return 1;
    }
    if (n % 2 != 0) {
        cout << "Number of subintervals must be even. Incrementing n by 1.\n";
        n++;
    }
    // Simpson's 1/3 Rule
    double h = (b - a) / n;
    double sum = f(a) + f(b);

    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        if (i % 2 == 0)
            sum += 2 * f(x);
        else
            sum += 4 * f(x);
    }
    // Compute the integral
    double result = (h / 3.0) * sum;

    // Output the result
    cout << "Approximate value of the integral of 1 / (1 + x^2) from "
         << a << " to " << b << " using Simpson's 1/3 Rule is: "
         << result << endl;

    return 0;
}