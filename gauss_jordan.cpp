#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    double a[n][n+1], p;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n+1; j++)
            cin >> a[i][j]; 
    for (int i = 0; i < n; i++){
        p = a[i][i];
        for (int j = 0; j < n + 1; j++)
            a[i][j] /= p;
        for (int k = 0; k < n; k++)
            if (k != i){
                p = a[k][i];
                for (int j = 0; j < n + 1; j++)
                    a[k][j] -= p * a[i][j];
            }
    }
    for (int i = 0; i < n; i++)
        cout << "x" << i + 1 << " = " << a[i][n] << endl;
}
