
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    double a[n][n], b[n], L[n][n], U[n][n];
    double y[n], x[n], sum;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    for (int i = 0; i < n; i++)
        cin >> b[i];

    // Initialize L and U
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            L[i][j] = 0;
            U[i][j] = 0;
        }
        L[i][i] = 1;
    }

    // LU Decomposition (Doolittle)
    for (int i = 0; i < n; i++)
    {

        for (int j = i; j < n; j++)
        {
            sum = 0;
            for (int k = 0; k < i; k++)
                sum += L[i][k] * U[k][j];

            U[i][j] = a[i][j] - sum;
        }

        for (int j = i + 1; j < n; j++)
        {
            sum = 0;
            for (int k = 0; k < i; k++)
                sum += L[j][k] * U[k][i];

            L[j][i] = (a[j][i] - sum) / U[i][i];
        }
    }

    // Forward Substitution: LY = B
    for (int i = 0; i < n; i++)
    {
        sum = 0;
        for (int j = 0; j < i; j++)
            sum += L[i][j] * y[j];

        y[i] = b[i] - sum;
    }

    // Backward Substitution: UX = Y
    for (int i = n - 1; i >= 0; i--)
    {
        sum = 0;
        for (int j = i + 1; j < n; j++)
            sum += U[i][j] * x[j];

        x[i] = (y[i] - sum) / U[i][i];
    }

    cout << "Solution:\n";
    for (int i = 0; i < n; i++)
        cout << "x[" << i + 1 << "] = " << x[i] << endl;

    return 0;
}
