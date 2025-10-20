/*
    CSES 1202 - Investigation
    https://cses.fi/problemset/task/1202
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

const ll N = 1e5+1, INF = 1e18, M = 1e9+7;
vector <pll> graph[N];
vector <ll> dist(N, INF), ways(N), mini(N,INF), maxi(N, 0);
ll n, m;

void self_add(ll &x, ll y = 1) { x = (x+y) % M; }

void dijkstra(ll no = 1) {
    vector<bool> visited(n+1, false);

    priority_queue <pll> q;
    q.push({0, no});
    
    dist[no] = mini[no] = maxi[no] = 0;
    ways[no] = 1;

    while (!q.empty()) {
        auto u = q.top().second;
        q.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (auto &[v, w] : graph[u]) {
            ll d = dist[u] + w;
            
            if (d < dist[v]) {
                mini[v] = mini[u]+1;
                maxi[v] = maxi[u]+1;

                ways[v] = ways[u]; // reset
                
                dist[v] = d; // update distance
                
                q.push({-d, v});
            }
            else if (d == dist[v]) {
                mini[v] = min(mini[v], mini[u]+1); // get min depth
                maxi[v] = max(maxi[v], maxi[u]+1); // get max depth
                self_add(ways[v], ways[u]);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    while (m--) {
        ll a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b,c});
    }

    dijkstra();
    cout << dist[n] << " " << ways[n] <<  " "
    << mini[n] << " " << maxi[n] << '\n';

    return 0;
}