#include <iostream>
#include <cmath>
using namespace std;

// Equation 1: f(x) = e^x - x^2
double f1(double x) {
    return exp(x) - x * x;
}

// Derivative of f1(x): f'(x) = e^x - 2x
double df1(double x) {
    return exp(x) - 2 * x;
}

// Equation 2: f(x) = sin(x) - x/2
double f2(double x) {
    return sin(x) - x / 2;
}

// Derivative of f2(x): f'(x) = cos(x) - 1/2
double df2(double x) {
    return cos(x) - 0.5;
}

// Equation 3: f(x) = x*log(x) - 1
double f3(double x) {
    return x * log(x) - 1;
}

// Derivative of f3(x): f'(x) = log(x) + 1
double df3(double x) {
    return log(x) + 1;
}

// Newton-Raphson Method
double newtonRaphson(double (*f)(double), double (*df)(double), double x0, double tol = 1e-6, int max_iter = 100) {
    double x = x0;
    for (int i = 0; i < max_iter; i++) {
        double fx = f(x);
        double dfx = df(x);
        if (fabs(dfx) < 1e-9) { // Avoid division by zero
            cout << "Derivative too small, stopping iteration." << endl;
            return x;
        }
        double x_new = x - fx / dfx;
        if (fabs(x_new - x) < tol) { // Check for convergence
            return x_new;
        }
        x = x_new;
    }
    cout << "Max iterations reached, solution may not be accurate." << endl;
    return x;
}

int main() {
    double x0;

    cout << "Enter initial guess for equation e^x - x^2 = 0: ";
    cin >> x0;
    cout << "Root: " << newtonRaphson(f1, df1, x0) << endl;

    cout << "\nEnter initial guess for equation sin(x) - x/2 = 0: ";
    cin >> x0;
    cout << "Root: " << newtonRaphson(f2, df2, x0) << endl;

    cout << "\nEnter initial guess for equation x*log(x) - 1 = 0: ";
    cin >> x0;
    if (x0 <= 0) {
        cout << "Invalid guess! x must be positive for log(x)." << endl;
    } else {
        cout << "Root: " << newtonRaphson(f3, df3, x0) << endl;
    }

    return 0;
}