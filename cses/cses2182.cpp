/*
    CSES 2182 - Divisor Analysis
    https://cses.fi/problemset/task/2182
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const ll M = 1e9+7;

ll exp(ll x, ll e) {
    ll ans = 1; x %= M;
    while (e > 0) {
        if (e % 2) ans = (ans*x) % M;
        x = (x*x) % M;
        e /= 2;       
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll x, n, k;
    cin >> n;
    
    ll num = 1, sum = 0, prod = 1;
    while (n--) {
        cin >> x >> k;

        num *= (k+1);
    }

    cout << num << ' ' << sum << ' ' << prod << '\n';

    return 0;
}