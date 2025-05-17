#include <iostream>
#include <cmath>
using namespace std;

double f(double x) {
    return 1.0 / (1.0 + x * x); // Change this if you want to integrate a different function
}

// Simpson's 3/8 Rule
double simpsonsThreeEighth(double a_deg, double b_deg, int n) {
    // n must be a multiple of 3
    if (n % 3 != 0) {
        cout << "Number of subintervals must be a multiple of 3. Adjusting n...\n";
        n += 3 - (n % 3); // Make n the next multiple of 3
    }

    double h = (b_deg - a_deg) / n;
    double sum = f(a_deg) + f(b_deg);

    for (int i = 1; i < n; i++) {
        double x = a_deg + i * h;
        if (i % 3 == 0)
            sum += 2 * f(x);
        else
            sum += 3 * f(x);
    }

    return (3 * h / 8.0) * sum;
}

int main() {
    double a_deg, b_deg;
    int n;

    cout << "Enter lower limit in degrees: ";
    cin >> a_deg;
    cout << "Enter upper limit in degrees: ";
    cin >> b_deg;

    // Convert degrees to radians
    double a = a_deg * (M_PI / 180.0);
    double b = b_deg * (M_PI / 180.0);

    cout << "Enter number of subintervals n (even for Simpson's 1/3): ";
    cin >> n;

    // Compute the integral
    double result = simpsonsThreeEighth(a, b, n);

    cout << "Approximate value of integral of sin(x) from " << a << " to " << b
         << " using Simpson's 3/8 rule is: " << result << endl;

    return 0;
}