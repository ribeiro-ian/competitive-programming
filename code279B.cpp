/*
    Codeforces 279B - Books
    https://codeforces.com/problemset/problem/279/B
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ll n, t;
    scanf("%lli %lli", &n, &t);

    ll a[n];
    for (int i = 0; i < n; i++) 
        scanf("%lli", &a[i]);

    int ans = 0; ll sum = 0;
    for (int i = 0, r = 0; i < n; i++) {
        while (r < n && sum + a[r] <= t) {
            sum += a[r];
            r++;
        }

        ans = max(ans, r - i);
        sum -= a[i]; // remove o primeiro em vez de recomeçar a soma
    }
 
    printf("%i\n", ans);

    return 0;
}