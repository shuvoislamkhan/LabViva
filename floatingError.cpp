//Understand the floating point error in using a built-in function like pow(cmath) and using direct multiplication
#include <iostream>
#include <cmath>  // For pow()
using namespace std;

int main() {
    double x;

    cout << "Enter a value for x: "; // input x = 1e8
    cin >> x;

    // Method 1: Using pow()
    double result_pow = pow(x, 4) + pow(x, 3) + pow(x, 2) + x + 1; ;

    // Method 2: Using direct multiplication
    double result_direct = x * x * x * x + x * x * x + x * x + x + 1;;

    // Print both results
    cout << "Using pow: " << result_pow << endl;
    cout << "Using direct multiplication: " << result_direct << endl;

    // Difference between results
    cout << "Difference: " << fabs(result_pow - result_direct) << endl;

    return 0;
}