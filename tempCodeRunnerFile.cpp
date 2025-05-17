#include <iostream>
#include <cmath>
using namespace std;
double f(double x)
{
return sin(x); // Example: sin(x)
}
// Forward difference method
double forward_diff(double x, double h)
{
return (f(x + h) - f(x)) / h;
}
// Backward difference method
double backward_diff(double x, double h)
{
return (f(x) - f(x - h)) / h;
}
// Central difference method
double central_diff(double x, double h)
{
}
{
return (f(x + h) - f(x - h)) / (2 * h);
int main()
double x = M_PI / 4; // 45 degrees
double h = 0.01;
cout << "Function: f(x) = sin(x)" << endl;
cout << "Point x = " << x << endl;
cout << "Step size h = " << h << endl << endl;
cout << "Forward Difference: " << forward_diff(x, h) << endl;
cout << "Backward Difference: " << backward_diff(x, h) << endl;
cout << "Central Difference: " << central_diff(x, h) << endl;
cout << "Exact Derivative (cos(x)): " << cos(x) << endl;
return 0;
}