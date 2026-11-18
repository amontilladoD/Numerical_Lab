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
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
        // Transformation
        double X = log(x[i]);
        double Y = log(y[i]);
        sumX += X;
        sumY += Y;
        sumX2 += X * X;
        sumXY += X * Y;
    }
    // Linear regression:
    // Y = A + BX
    // A = ln(a)
    // B = b
    double b = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
    double A = (sumY - b * sumX) / n;
    // a = e^A
    double a = exp(A);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "Equation: y = "
         << a << " * x^"
         << b << endl;
}