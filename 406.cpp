#include <iostream>
#include <cmath>
using namespace std;

// Function to be integrated
double f(double x) {
    return 1.0 / (1.0 + x * x); // Example: f(x) = 1 / (1 + x^2)
}

// Simpson's 3/8 Rule
double simpsonsThreeEighth(double a, double b, int n) {
    // n must be a multiple of 3
    if (n % 3 != 0) {
        cout << "Number of subintervals must be a multiple of 3. Adjusting n...\n";
        n += 3 - (n % 3); // Make n the next multiple of 3
    }

    double h = (b - a) / n;
    double sum = f(a) + f(b);

    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        if (i % 3 == 0)
            sum += 2 * f(x);
        else
            sum += 3 * f(x);
    }

    return (3 * h / 8.0) * sum;
}

int main() {
    double a, b;
    int n;

    // User input
    cout << "Enter lower limit a: ";
    cin >> a;
    cout << "Enter upper limit b: ";
    cin >> b;
    cout << "Enter number of subintervals n (must be multiple of 3): ";
    cin >> n;

    // Compute the integral
    double result = simpsonsThreeEighth(a, b, n);

    // Output result
    cout << "Approximate value of integral of 1 / (1 + x^2) from " << a << " to " << b
         << " using Simpson's 3/8 rule is: " << result << endl;

    return 0;
}