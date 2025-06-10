/*
    CSES 1651 - Range Update Queries
    https://cses.fi/problemset/task/1651
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const ll MAXN = 2*1e5+1;
ll bit[MAXN], n, q;

// soma v em V[i]
void upd(ll i, ll v) {
    // lsb(i) = i&-i
    for (; i <= n; i += (i&-i))
        bit[i] += v;
}

// soma de [1, i]
ll sum(ll i) {
    ll ans = 0;
    
    for (; i > 0; i -= (i&-i))
        ans += bit[i];
        
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> q;

    vector <ll> vet(n+1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> vet[i];
        upd(i, vet[i]);
    }
    
    while (q--) { // O(q)
        ll op; cin >> op;

        if (op == 1) {
            ll a, b, u;
            cin >> a >> b >> u;

            upd(b,u); // O(q * logN)
        }
        else {
            ll k; cin >> k;

            cout << vet[k] << "\n";
        }
    }

    return 0;
}