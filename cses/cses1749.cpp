/*
    CSES 1749 - List Removals
    https://cses.fi/problemset/task/1749
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll N = 2e5+1;
vector<ll> segtree(2 * N);
ll n;

void update(int i) {
    for (segtree[i += n]++; i > 1; i /= 2)
        segtree[i / 2]++;
}

ll query(int l, int r) {  // sum on interval [l, r]
    ll res = 0;

    for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
        if (l & 1) res += segtree[l++];
        if (r & 1) res += segtree[--r];
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    vector<int> v(n), taken(n, 0);

    for (int i = 0; i < n; ++i)
        cin >> v[i];
    
    for (int i = 0; i < n; ++i) {
        int idx; cin >> idx;
        idx--;

        while (taken[idx])
            idx += query(0, idx);
        
        update(idx);
        taken[idx] = true;
        cout << v[idx] << " ";
    }
    cout << '\n';

    return 0;
}