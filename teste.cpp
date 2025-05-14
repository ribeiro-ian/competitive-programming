#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    double x, t, a;
    int tc = 7;
    
    double ans = 0, res = 0;
    while (tc--) {
        cin >> x >> t >> a;

        ans = sqrt( 2 * a * x );
        res += ans;
    }
    printf("%.3f\n", res/7);

}

/*
1 3 3 2 1 1 6 2

*/