//Cubic Polynomial (Degree 3): ax^3+bx^2+cx+d=0
#include <iostream>
#include <cmath>
using namespace std;
// Define the function f(x) = ax^3 + bx^2 + cx + d 
double f(double x, double a, double b, double c, double d) {
    return a * pow(x, 3) + b * pow(x, 2) + c * x + d;
}
double df(double x, double a, double b, double c) {
    return 3 * a * pow(x, 2) + 2 * b * x + c;
}
// Newton-Raphson method to find root
double newtonRaphson(double a, double b, double c, double d, double x0, double tol = 1e-6, int
max_iter = 1000) {
    double x = x0;
    for (int i = 0; i < max_iter; i++)
    {
        double fx = f(x, a, b, c, d);
        double dfx = df(x, a, b, c);
        if (fabs(dfx) < 1e-9) {
            // Avoid division by zero
            cout << "Derivative too small, stopping iteration." << endl;
            return x;
            }
            double x_new = x - fx / dfx;
            if (fabs(x_new - x) < tol) {
            return x_new;
        }
        x = x_new;
    }
    cout << "Max iterations reached, solution may not be accurate." << endl;
    return x;
}
int main() {
    double a, b, c, d, x0;
    cout << "Enter coefficients a, b, c, d: ";
    cin >> a >> b >> c >> d;
    cout << "Enter initial guess: ";
    cin >> x0;
    double root = newtonRaphson(a, b, c, d, x0);
    cout << "Approximate root: " << root << endl;
    return 0;
}