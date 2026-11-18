#include<bits/stdc++.h>
using namespace std;
double f(double x){
    return x*x - 4;
}
double df(double x){
    double h = 1e-5;
    return (f(x + h) - f(x - h))/(2*h);
}
int main(){
    double x1, x0=3, e = 1e-5;
    while(1){
        x1 = x0 - f(x0)/df(x0);
        if(fabs(x1-x0) < e)
            break;
        x0 = x1;
    }
    cout << x1;
}