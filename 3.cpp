//Cubic Polynomial (Degree 3): ax^3+bx^2+cx+d=0
#include <iostream>
#include <cmath>
#define EPSILON 1e-6
using namespace std;
double func(double x, double a, double b, double c, double d) {
return a*x*x*x + b*x*x + c*x + d;
}
// Derivative of f(x) -> f'(x) = 3ax^2 + 2bx + c
double derivFunc(double x, double a, double b, double c) {
return 3*a*x*x + 2*b*x + c;
}
// Newton-Raphson method to find root
double newtonRaphson(double a, double b, double c, double d, double x) {
while (fabs(func(x, a, b, c, d)) > EPSILON) {
double f_x = func(x, a, b, c, d);
double df_x = derivFunc(x, a, b, c);
if (df_x == 0) {
cout << "Derivative is zero. Try a different initial guess." << endl;
return NAN;
}
x = x - f_x / df_x;
}
return x;
}
int main(){
double a, b, c, d, x;
cout << "Enter coefficients a, b, c, d: ";
cin >> a >> b >> c >> d;
cout << "Enter initial guess: ";
cin >> x;
double root = newtonRaphson(a, b, c, d, x);
if (!isnan(root))
{
cout << "One root of the equation is: " << root << endl;
}
return 0;
}