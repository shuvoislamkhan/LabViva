//Quadratic Polynomial (Degree 2): ax^2+bx+c=0
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, b, c, r;
    cout << "Enter a, b, c: ";
    cin >> a >> b >> c;

    double d = b * b - 4 * a * c; // Discriminant
    if (d == 0) {
        double r = -b / (2 * a);
        cout << "Roots are real and equal: " << r << endl;
    }
    else if (d > 0) {
        double r1 = (-b + sqrt(d)) / (2 * a);
        double r2 = (-b - sqrt(d)) / (2 * a);
        cout << "Roots are real and distinct: " << r1 << " , " << r2 << endl;
    }
    else {
        double realP = -b / (2 * a);
        double imaP = sqrt(-d) / (2 * a);
        cout << "Roots are complex: " << realP << " + " << imaP << " i " << " and " << realP << " - " << imaP << " i" << endl;
    }
    return 0;
}

