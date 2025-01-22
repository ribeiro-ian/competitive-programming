#include <bits/stdc++.h>
using namespace std;

const double MAX = 1e10+1;

double f(double y){
    return y*y + sqrt(y);
}

double bs(double x){
    double l = 1, r = MAX;

    while (abs(l-r) > 1e-6){
        double mid = (l+r)/2;

        if (f(mid) > x)
            r = mid;
        else 
            l = mid;
    }

    return l;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    double x;
    cin >> x;
    printf("%lf\n", bs(x));

    return 0;
}
