#include<iostream>
using namespace std;

int main() {
    double a, b;
    cout << "Enter a and b (for ax + b = 0): ";
    cin >> a >> b;

    if (a == 0) {
        cout << (b == 0 ? "Infinite solutions." : "No solution.") << endl;
    } else {
        cout << "Solution: x = " << -b / a << endl;
    }
    return 0;
}