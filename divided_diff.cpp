#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    double x[n], y[n][n], p=1, xp, ans;
    for(int i=0; i<n; i++)
        cin >> x[i] >> y[i][0];
    for(int j=1; j<n; j++){
        for(int i=0; i<n-j; i++){
            y[i][j] = (y[i+1][j-1] - y[i][j-1])/(x[i+j]-x[i]);
        }
    }
    cin >> xp;
    ans = y[0][0];
    for(int i=1; i<n; i++){
        p *= (xp - x[i-1]);
        ans += p*y[0][i];
    }
    cout << ans << endl;
}