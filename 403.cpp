#include <iostream>
#include <cmath>
using namespace std;

// Define the function to differentiate
double f(double x) {
    return exp(x); // Modified function: f(x) = e^x
}

// Forward difference method
double forward_diff(double x, double h) {
    return (f(x + h) - f(x)) / h;
}

// Backward difference method
double backward_diff(double x, double h) {
    return (f(x) - f(x - h)) / h;
}

// Central difference method
double central_diff(double x, double h) {
    return (f(x + h) - f(x - h)) / (2 * h);
}

int main() {
    double x;
    double h;

    cout << "Function: f(x) = e^x" << endl;
    cout << "Enter point x: ";
    cin >> x;
    cout << "Enter step size h: ";
    cin >> h;

    cout << endl;
    cout << "Results:" << endl;
    cout << "Forward Difference:  " << forward_diff(x, h) << endl;
    cout << "Backward Difference: " << backward_diff(x, h) << endl;
    cout << "Central Difference:  " << central_diff(x, h) << endl;
    cout << "Exact Derivative (e^x): " << exp(x) << endl;

    return 0;
}