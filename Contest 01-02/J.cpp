#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){
    int n, h, c, l;
    while (cin >> n){
        cin >> h >> c >> l;

        double ans = l * sqrt(pow(h,2) + pow(c,2));

        printf("%.4f\n", ans*n/10e3);
    }

    return 0;
}
