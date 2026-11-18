
#include <bits/stdc++.h>
using namespace std;

double simpson13(double x[], double y[], int n)
{
    double h = (x[n] - x[0]) / n;
    double sum = y[0] + y[n];

    for (int i = 1; i < n; i++)
    {
        if (i % 2 == 0)
            sum += 2 * y[i];
        else
            sum += 4 * y[i];
    }

    return (h / 3) * sum;
}

double simpson38(double x[], double y[], int n)
{
    double h = (x[n] - x[0]) / n;
    double sum = y[0] + y[n];

    for (int i = 1; i < n; i++)
    {
        if (i % 3 == 0)
            sum += 2 * y[i];
        else
            sum += 3 * y[i];
    }

    return (3 * h / 8) * sum;
}

int main()
{
    int n;
    cin >> n;

    double x[n + 1], y[n + 1];

    for (int i = 0; i <= n; i++)
        cin >> x[i] >> y[i];

    if (n % 2 == 0)
        cout << "Simpson 1/3 = " << simpson13(x, y, n);
    else if (n % 3 == 0)
        cout << "Simpson 3/8 = " << simpson38(x, y, n);
    else
        cout << "Neither rule is directly applicable";
}
