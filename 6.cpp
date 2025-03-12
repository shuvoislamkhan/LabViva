//Solution of system of linear equations
//a1x+b1y=c1
//a2x+b2y=c2
#include <iostream>
using namespace std;
int main()
{
    // Declare the coefficients
    double a1, b1, c1, a2, b2, c2;
    //Input the coefficients for the system of equations
    cout << "Enter a1, b1, c1 (for the first equation): ";
    cin >> a1 >> b1 >> c1;
    cout << "Enter a2, b2, c2 (for the second equation): ";
    cin >> a2 >> b2 >> c2;
    //Calculate the determinant (denominator)
    double determinant = a1 * b2 - a2 * b1;
    if(determinant == 0)
    {
        cout << "The system has no unique solution (determinant is zero)." << endl;
    }
    else{
    //Calculate x and y using Cramer's rule
        double x = (c1 * b2 - c2 * b1) / determinant;
        double y = (a1 * c2 - a2 * c1) / determinant;
        //Output the results
        cout << "The solution is:" << "x = " << x << " and y = " << y << endl;
    }    
    return 0;
}