#include <bits/stdc++.h>
using namespace std;
double f(double x, double y){
    return 2*x - 1;
}
int main(){
    double x, y, h, xn;
    double k1, k2, k3, k4;
    cout << "Enter x0, y0, h, xn: ";
    cin >> x >> y >> h >> xn;
    int n = round((xn - x)/h);
    for (int i=0; i<n; i++)
    {
        k1 = h * f(x, y);
        k2 = h * f(x + h / 2, y + k1 / 2);
        k3 = h * f(x + h / 2, y + k2 / 2);
        k4 = h * f(x + h, y + k3);
        y = y + (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        x = x + h;
    }
    cout << "Final y = " << y << endl;
    return 0;
}
