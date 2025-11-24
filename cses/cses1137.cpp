/*
    CSES 1137 - Subtree Queries
    https://cses.fi/problemset/task/1137
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll N = 2e5+1;
vector<ll> tree[N], order(1), subSize(N), v(N), pos(N);
ll n, q;

struct SegTree {
    vector<ll> tree;
    int n;
    
    SegTree(ll size) {
        n = 1;
        while (n < size) n *= 2;
        tree.assign(2 * n, 0);
    }
    
    void update(ll idx, ll val) {
        idx += n;
        tree[idx] = val;

        for (ll i = idx/2; i >= 1; i /= 2) 
            tree[i] = tree[2*i] + tree[2*i + 1];
    }
    
    ll query(ll l, ll r) {
        ll sum = 0;
        for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
            if (l & 1) sum += tree[l++];
            if (r & 1) sum += tree[--r];
        }
        return sum;
    }
};

void dfs(ll no = 1, ll p = -1) {
    subSize[no] = 1;
    pos[no] = order.size()-1;
    order.push_back(no);

    for (auto &v : tree[no]) 
        if (v != p) {
            dfs(v, no);
            subSize[no] += subSize[v];
        }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> v[i];

    for (int i = 1; i < n; ++i) {
        ll a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs();
    SegTree segtree(n);
    for (int i = 1; i <= n; ++i) 
        segtree.update(i-1, v[order[i]]);

    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            ll node, x;
            cin >> node >> x;
            segtree.update(pos[node], x);
        }
        else {
            ll node; cin >> node;
            cout << segtree.query(pos[node], pos[node] + subSize[node]-1) << '\n';
        }
    }

    return 0;
}