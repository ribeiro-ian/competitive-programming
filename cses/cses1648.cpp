/*
    CSES 1648 - Dynamic Range Sum Queries
    https://cses.fi/problemset/task/1648
*/
 
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
const ll N = 2e5+1;
vector<ll> tree(2*N);
ll n, q;
 
ll sum(int l, int r) {
    ll s = 0;
    for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
        if (l & 1) s += tree[l++];
        if (r & 1) s += tree[--r];
    }
    return s;
}
 
void upd(int i, ll x) {
    i+=n; x -= tree[i];
    tree[i] += x;
 
    for (i /= 2; i >= 1; i /= 2)
        tree[i] += x;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
 
    cin >> n >> q;
    for (int i = 0; i < n; ++i)
        cin >> tree[i+n];
 
    for (int i = 2*n-1; i > 1; --i)
        tree[i/2] += tree[i];
 
    while (q--) {
        int op; cin >> op;
        
        if (op == 1) {
            ll k, u;
            cin >> k >> u;
            upd(--k, u);
        }
        else {
            int l, r;
            cin >> l >> r;
            cout << sum(--l,--r) << '\n';
        }
    }
 
    return 0;
}