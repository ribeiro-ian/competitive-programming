/*
    CSES 1676 - Road Construction
    https://cses.fi/problemset/task/1676
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+1;

vector<int> par(N), sz(N,1);
priority_queue <int> sizes;
int total;

int find(int v) {
    if (v == par[v])
        return v;
    return find(par[v]);
}

void join(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b) return; // already on same set
    total--;
    if (sz[a] < sz[b]) swap(a,b);

    if (sz[a] == sizes.top()) sizes.pop();
    if (sz[b] == sizes.top()) sizes.pop();

    par[b] = a;
    sz[a] += sz[b];

    sizes.push(sz[a]);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m;
    cin >> n >> m;

    total = n;
    for (int i = 1; i <= n; ++i) par[i] = i, sizes.push(1);
    while (m--) {
        int a, b;
        cin >> a >> b;

        join(a,b);
        cout << total << " " << sizes.top() << '\n';
    }

    return 0;
}