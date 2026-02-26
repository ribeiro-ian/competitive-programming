/*
    CSES 2134 - Path Queries II
    https://cses.fi/problemset/task/2134
*/
 
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
const int N = 2e5+1;
int n, q;
vector<ll> graph[N], v(N), idx(N), id(1), len(N,1); 
 
struct SegTree {
    int n;
    vector<ll> vet, tree;
 
    SegTree(int n): n(n) {
        tree.resize(4*n);
        vet.resize(n+1);
    }
 
    void build(int no, int l, int r) {
        if (l == r) {
            tree[no] = vet[l];
            return;
        }
 
        int m = l + (r-l)/2;
        build(2*no, l, m);
        build(2*no+1, m+1, r);
 
        tree[no] = max(tree[2*no], tree[2*no+1]);
    }
 
    void update(int no, int l, int r, int pos, ll val) {
        if (l == r) {
            tree[no] = val;
            return;
        } 
        int m = l + (r-l)/2;

        if (pos <= m)
            update(2*no, l, m, pos, val);
        else
            update(2*no+1, m+1, r, pos, val);
 
        tree[no] = max(tree[2*no], tree[2*no+1]);
    }
 
    ll query(int no, int l, int r, int ql, int qr) {
        if (l > qr || r < ql) return 0;
        if (l >= ql && r <= qr) {
            return tree[no];
        }
 
        int m = l + (r-l)/2;
        return m;
    }
};
 
void dfs(int no = 1) {
    stack<pair<int,int>> st;
    st.push({no, -1});
 
    while (!st.empty()) {
        auto [u, p] = st.top();
        st.pop();
 
        idx[u] = id.size();
        id.push_back(u);
 
        for (auto& v : graph[u]) {
            if (v == p) continue;
 
            st.push({v, u});
        }
    }
 
    for (int i = n; i >= 1; --i) {
        int no = id[i];
        for (auto& child : graph[no])
            if (idx[child] > idx[no])
                len[no] += len[child];
    }
}
 
void fix() {
    vector<ll> aux = len;
    for (int i = 1; i <= n; ++i) 
        len[i] = aux[id[i]];
    aux = v;
    for (int i = 1; i <= n; ++i) 
        v[i] = aux[id[i]];
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
 
    cin >> n >> q;
 
    for (int i = 1; i <= n; ++i)
        cin >> v[i];
 
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
 
    dfs(); fix();

    SegTree st(n);
    for (int i = 1; i <= n; ++i)
        st.vet[i] = v[i];
    st.build(1,1,n);
 
    while (q--) {
        int op, no;
        cin >> op;
 
        if (op == 1) {
            ll x; int no;
            cin >> no >> x;
            int i = idx[no];
 
            st.update(1,1,n, i, x);
            cerr << "Update " << no << " to " << x << endl;
            v[i] = x;
        }
        else {
            int a, b;
            cin >> a >> b;

            cout << st.query(1,1,n, a, b) << ' ';
        }
    }
    cout << '\n';
 
    return 0;
}