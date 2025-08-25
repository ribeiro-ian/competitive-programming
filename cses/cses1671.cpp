/*
    CSES 1671 - Shortest Routes I
    https://cses.fi/problemset/task/1671
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
const ll INF = 1e18;

vector <vector <pii>> adj;
vector <ll> dist;
ll n, m;

void dijsktra(ll s) {
    vector <bool> visited(n+1, false);
    dist.assign(n+1, INF);

    priority_queue <pii> q;
    dist[s] = 0;
    q.push({0, s});

    while (!q.empty()) {
        ll u = q.top().second;
        q.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (auto [v,w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                q.push({-dist[v], v});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    adj.assign(n+1, vector <pii> ());

    while (m--) {
        ll a, b, c;
        cin >> a >> b >> c;

        adj[a].push_back({b, c});
    }

    dijsktra(1);

    for (int i = 1; i <= n; ++i) {
        cout << dist[i] << ' ';
    }
    cout << '\n';

    return 0;
}
