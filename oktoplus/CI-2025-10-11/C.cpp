/*
    CSES 1095 - Exponentiation
    https://cses.fi/problemset/task/1095
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const ll M = 1e9+7;

ll exp(ll x, ll e) {
    x %= M;
    ll ans = 1;

    while (e >= 1) {
        if (e % 2 == 1) ans = (ans * x) % M;
        x = (x*x) % M;
        e /= 2;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll n, a, b; cin >> n;
    while (n--)  {
        cin >> a >> b;
        cout << exp(a, b) << '\n';
    }

    return 0;
}