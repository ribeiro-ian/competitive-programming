/*
    CSES 1095 - Exponentiation
    https://cses.fi/problemset/task/1095
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const ll mod = 1e9+7;

ll fast_pow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b % 2 == 1) res = res * a % mod;
        a = a * a % mod;
        b /= 2;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll t; cin >> t;
    while (t--) {
        ll a, b; cin >> a >> b;

        cout << fast_pow(a,b) << '\n';
    }

    return 0;
}