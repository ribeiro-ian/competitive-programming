/*
    SPOJ - Easy Dijkstra Problem
    https://www.spoj.com/problems/EZDIJKST/en/
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void solve() {
    const ll INF = 1e18;
    
    ll n, m;
    cin >> n >> m;
    vector<pair<ll,ll>> graph[n+1];
    vector<ll> dist(n+1, INF);

    while (m--) {
        ll a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    
    ll st, end;
    cin >> st >> end;

    priority_queue<pair<ll,ll>> pq;
    dist[st] = 0;
    pq.push({0, st});

    while (!pq.empty()) {
        auto u = pq.top().second;
        pq.pop();

        for (auto &[v,w] : graph[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({-dist[v], v});
            }
        }
    }

    if (dist[end] == INF) {
        cout << "NO\n";
    }
    else {
        cout << dist[end] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tc; cin >> tc;
    while (tc--) solve();

    return 0;
}