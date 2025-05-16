//Cubic Polynomial (Degree 4): ax^4+bx^3+cx^2+dx+e=0
#include <iostream>
#include <cmath>
using namespace std;
// Define the function f(x) = ax^4 + bx^3 + cx^2 + dx + e
double f(double x, double a, double b, double c, double d, double e) {
    return a * x * x * x * x + b * x * x * x + c * x * x + d * x + e;
}
double df(double x, double a, double b, double c, double d) {
    return 4 * a * x * x * x + 3 * b * x * x + 2 * c * x + d;
}
// Newton-Raphson method to find root
double newtonRaphson(double a, double b, double c, double d, double e, double x0, double tol = 1e-6, int
max_iter = 1000) {
    double x = x0;
    for (int i = 0; i < max_iter; i++) {
        double fx = f(x, a, b, c, d, e);
        double dfx = df(x, a, b, c, d);
        if (fabs(dfx) < tol) {
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
int main()
{
    double a, b, c, d, e, x0;
    cout << "Enter coefficients a, b, c, d, e: ";
    cin >> a >> b >> c >> d >> e;
    cout << "Enter initial guess: ";
    cin >> x0;
    double root = newtonRaphson(a, b, c, d, e, x0);
    cout << "Approximate root: " << root << endl;
    return 0;
}