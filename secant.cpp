#include<bits/stdc++.h>
using namespace std;
double f(double x){
    return 3*x - cos(x) - 1;
}
int main(){
    double x0, x1, next, e = 1e-6;
    cin >> x0 >> x1;
    while(1){
        next = x1 - (f(x1)*(x1 - x0)) / (f(x1) - f(x0));
        if(fabs(next - x1) < e)
            break;
        x0 = x1;
        x1 = next;
    }
    cout << next;
}
