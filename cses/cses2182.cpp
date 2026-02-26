/*
    CSES 2182 - Divisor Analysis
    https://cses.fi/problemset/task/2182
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll,ll>;

const ll M = 1e9+7;

inline void self_prod(ll& x, ll y) {
    x = (x * y) % M;
}

ll exp(ll x, ll e) {
    ll ans = 1; x %= M;
    while (e > 0) {
        if (e % 2) self_prod(ans, x);
        self_prod(x,x);
        e /= 2;
    }
    return ans;
}

ll mod_inv(ll x) {
    return exp(x, M-2);
}

vector<pii> fact;

void solve(ll& div, ll& sum, ll& prod) {
    div = 1, sum = 1, prod = 1;
    ll d = 1;

    for (auto& [p,e]: fact) {
        self_prod(sum, (((exp(p, e+1)-1 + M) % M) * mod_inv(p-1)) % M);
        self_prod(div, e+1);

        auto val = exp(p, e * (e + 1) / 2);

        prod = (exp(prod, e + 1) * exp(val, d)) % M;

        // Update the count of divisors
        d = (d * (e + 1)) % (M - 1);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll n; cin >> n;
    fact.resize(n);
    
    for (auto& [p,e] : fact) 
        cin >> p >> e;

    ll numDiv, sumDiv, prodDiv;
    solve(numDiv, sumDiv, prodDiv);

    cout << numDiv << ' ' << sumDiv << ' ' << prodDiv << '\n';

    return 0;
}