/*
    Codeforces 1430B - Barrels
    https://codeforces.com/contest/1430/problem/B
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ll tc, n, k;

    scanf("%lli", &tc);
    while (tc--) {
        scanf("%lli%lli", &n, &k);
        ll b[n];

        for (int i = 0; i < n; i++) {
            scanf("%lli", &b[i]);
        }
        
        sort(b,b+n);

        ll sum = b[n-1];
        while (k) {
            sum += b[n-1 - k];
            k--;
        }

        printf("%lli\n", sum);
    }

    return 0;
}