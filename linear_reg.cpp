#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    double x[n], y[n];
    double sumX = 0;
    double sumY = 0;
    double sumX2 = 0;
    double sumXY = 0;
    for (int i = 0; i < n; i++){

        cin >> x[i] >> y[i];

        sumX += x[i];
        sumY += y[i];
        sumX2 += x[i] * x[i];
        sumXY += x[i] * y[i];
    }
    double b = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
    double a = (sumY - b * sumX) / n;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "Equation: y = "
         << a << " + "
         << b << "x" << endl;
    cout << "Value of y = " << a+b*2 << endl;
}