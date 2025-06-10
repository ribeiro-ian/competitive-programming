/*
    CSES 1734 - Distinct Values Queries
    https://cses.fi/problemset/task/1734
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const ll MAXN = 2*1e5+1;
set <ll> bit[MAXN];
ll n, q, vet[MAXN];

void upd(ll i) {
    // lsb(i) = i&-i
    for (; i <= n; i += (i&-i)) {
        ll v = vet[i];
        bit[i].insert(v);
    }
}

// soma de [1, i]
ll sum(ll i) {
    ll ans = 0;
    
    for (; i > 0; i -= (i&-i))
        ans += bit[i].size();
        
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> vet[i];
        upd(i);
    }

    cerr << "bit:\n";
    for (int i = 1; i <= n; i++)
        cerr << sum(i) << " "; cerr << "\n";
    
    while (q--) { // O(q)
        ll a, b;
        cin >> a >> b;

        cout << sum(b) - sum(a-1) << endl;
    }

    return 0;
}