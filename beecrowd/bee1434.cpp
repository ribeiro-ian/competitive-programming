/*
    Beecrowd 1434 - Patrulheiros Romanos
    https://judge.beecrowd.com/pt/problems/view/1434
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll c, r, n, s;
vector<set<pair<ll,ll>>> graph;
vector<ll> iic;

ll updateIIC(ll prev, ll next, ll d) {
    ll sum = 0;
    iic[prev] = 0;

    for (ll j = 1; j <= d; j++) {
        if (n <= 0) 
            return sum;
        
        for (ll i = 1; i <= c; ++i) {
            if (j == d && i == next)
                iic[next] = -1;

            iic[i]++;
            sum += iic[i];
        }
        n--;
    }
    
    iic[next] = 0;
    return sum;
}

pair<ll,ll> cycle(ll u) {
    auto [nextId, dist] = (*graph[u].begin());
    for (auto& [v, d] : graph[u]) {
        if (iic[v] > iic[nextId]) {
            nextId = v;
            dist = d;
        }
    }

    return {nextId, dist};
}

void solve() {
    if (!c) return;
    graph.assign(c+1, {});
    iic.assign(c+1, 0);

    while(r--) {
        ll x, y, d;
        cin >> x >> y >> d;

        graph[x].insert({y,d});
        graph[y].insert({x,d});
    }
    
    ll ans = 0;
    while(n) {
        auto [next,dist] = cycle(s);
        int total = updateIIC(s, next, dist);
        ans += total;
        s = next;
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    while (cin >> c >> r >> n >> s)
        solve();

    return 0;
}