/*
    CSES 3426 - Sliding Window Xor
    https://cses.fi/problemset/task/3426
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll a, b, c;
inline ll calc(ll x) {
    return (a*x + b) % c;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll n, k, x;
    cin >> n >> k;
    cin >> x >> a >> b >> c;

    // include first val
    ll ans, amount = x, last = x;
    for (int i = 1; i < k; ++i) {
        x = calc(x);
        amount ^= x;
    }
    ans = amount;
    
    for (int i = k; i < n; ++i) {
        amount ^= last;
        last = calc(last);

        x = calc(x);
        amount ^= x;

        ans ^= amount;
    }
    cout << ans << '\n';

    return 0;
}