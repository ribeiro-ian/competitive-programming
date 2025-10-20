/*
    CSES 1750 - Planets Queries I
    https://cses.fi/problemset/task/1750
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const ll K = 1e9, N = 2*1e5+1;
ll succ[N+1][(ll)log2(K)];

ll pre(ll x, ll k) {
    if (k <= 1) return succ[x][1];
    
    return succ[x][k] = pre(pre(x, k/2),k/2);
}

ll query(ll x, ll y, ll k) {
    if (k <= 0) return succ[y][1];

    ll next = k-1;
    for (; next > 0; --next) {
        if (x & (1<<next)) break;
    }
    cerr << y << " & " << (1<<next) << '\n';

    return query(x, succ[y][1<<k], next);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll n, q;
    cin >> n >> q;

    for (int i = 1; i <= n;++ i) {
        cin >> succ[i][1];
    }

    // pre process
    for (int i = 1; i <= n; ++i) {
        pre(i, (ll)log2(K));
    }

    while (q--) {
        ll x, k;
        cin >> x >> k;

        ll logk = log2(k);
        ll ans = query(k, x, logk);
        cout << ans << '\n';
    }

    return 0;
}