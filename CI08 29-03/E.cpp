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
    for (int i = 0; i < n; i++) {
        scanf("%lli", &a[i]);
    }

    ll l = 0, r = 0, sum = 0, ans = 0;
    while (r < n) {
        sum += a[r];
        r++;
        
        while (sum > t) {
            sum -= a[l];
            l++;
        }
        ans = max(ans, r - l + 1);
    }

    printf("%lli\n", ans - 1);

    return 0;
}