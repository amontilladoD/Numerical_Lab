#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    double a[n][n+1], p, x[n];
    for(int i=0; i<n; i++)
        for(int j=0; j<=n; j++)
            cin >> a[i][j];
    for(int i=0; i<n; i++){
        p = a[i][i];
        for(int j=0; j<=n; j++){
            a[i][j] /= p;
        }
        for(int k=i+1; k<n; k++){
            if(k!=i){
                p = a[k][i];
                for(int j=0; j<=n; j++) 
                    a[k][j] -= p*a[i][j];
            }
        }
    }
    for(int i=n-1; i>=0; i--){
        x[i] = a[i][n];
        for (int k = i + 1; k < n; k++)
            x[i] -= a[i][k] * x[k];
    }
}