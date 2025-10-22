#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;

const int N = 1e5+1;
vector<ll> par(N);
ll total;

int find(ll v) {
    if (v == par[v])
        return v;
    return find(par[v]);
}

bool join(ll a, ll b) {
    a = find(a);
    b = find(b);

    if (a == b) return false;
    if (a > b) swap(a,b);
    total--;

    par[b] = a;
    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m;
    cin >> n >> m;

    total = n;
    for (int i = 1; i <= n; ++i) par[i] = i;

    vector <vector<ll>> edges;
    while (m--) {
        ll a, b, c;
        cin >> a >> b >> c;
        edges.push_back({c,a,b});
    }
    sort(edges.begin(), edges.end());

    ll ans = 0;
    for (int i = 0; i < edges.size(); ++i) {
        ll a = edges[i][1],
           b = edges[i][2],
           c = edges[i][0];

        if (join(a,b)) ans += c;
    }
    if (total == 1)
        cout << ans << '\n';
    else
        cout << "IMPOSSIBLE\n";

    return 0;
}