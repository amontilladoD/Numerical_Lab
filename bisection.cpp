#include <iostream>
#include <cmath>
using namespace std;
double f(double x) {
    return x*x - 4;
}
int main() {
    double x0, x1, x2, e;
    cin >> x1 >> x2 >> e;
    do {
        x0 = (x1 + x2) / 2;
        if (f(x0) * f(x1) < 0)
            x2 = x0;
        else
            x1 = x0;
    } while (fabs(f(x0)) > e);
    cout << "Root = " << x0;
}
