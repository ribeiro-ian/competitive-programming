/*
    CSES 1079 - Binomial Coefficients
    https://cses.fi/problemset/task/1079
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll M = 1e9+7, N = 1e6+1;
vector<ll> fac(N), inv(N);

ll exp(ll x, ll e) {
    ll res = 1; x %= M;
    while (e > 0) {
        if (e & 1)
            res = res * x % M;
        x = x * x % M;
        e /= 2;
    }
    return res;
}

void solve() {
    ll n, k;
    cin >> n >> k;

    cout << fac[n] * inv[k] % M * inv[n-k] % M << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    fac[0] = 1;
    for (int i = 1; i < N; ++i) 
        fac[i] = i * fac[i-1] % M;    
    inv[N-1] = exp(fac[N-1], M-2);
    for (int i = N-1; i > 0; --i) 
        inv[i-1] = i * inv[i] % M;    

    int tc; cin >> tc;
    while (tc--) solve();

    return 0;
}