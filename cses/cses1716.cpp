/*
    CSES 1716 - Distributing Apples
    https://cses.fi/problemset/task/1716
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

ll factorial(ll x) {
    if (x < N) return fac[x];
    
    ll res = fac[N-1];
    for (ll i = N; i <= x; ++i) // (1e6..x) = x! 
        res = res * i % M;
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    fac[0] = 1;
    for (int i = 1; i < N; ++i) 
        fac[i] = i * fac[i-1] % M;

    inv[N-1] = exp(fac[N-1], M-2);
    for (int i = N-1; i > 0; --i) 
        inv[i-1] = i * inv[i] % M;

    ll n, k;
    cin >> n >> k;

    cout << factorial(n+k-1) * inv[k] % M * inv[n-1] % M << '\n';    

    return 0;
}