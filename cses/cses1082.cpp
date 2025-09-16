/*
    CSES 1082 - Sum of Divisors
    https://cses.fi/problemset/task/1082
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
constexpr ll mod = 1e9+7;

ll sum(ll n) {
    ll s = 0;

    for (ll i = 1; i*i <= n; ++i) {
        if (n%i != 0) continue;

        if (n/i == i) s = (s + i) % mod;
        else s = (s + (i + n/i) % mod) % mod;
    }
    return s;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll n, ans = 0; cin >> n;
    for (ll i = 1; i <= n; ++i) {
        ans = (ans + sum(i)) % mod;
    }
    cout << ans << '\n';

    return 0;
}