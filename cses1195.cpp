/*
    CSES 1195 - Flight Discount
    https://cses.fi/problemset/task/1195
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;

vector <vector <pll>> adjA, adjB;
const ll INF = 1e18;
ll n, m;

vector<ll> dijkstra(ll no, vector <vector<pll>> &adj) {
    vector <bool> visited(n+1, false);
    vector <ll> dist (n+1, INF);
    priority_queue <pll> q;
    
    q.push({0, no});
    dist[no] = 0;

    while (!q.empty()) {
        ll curr = q.top().second;
        q.pop();

        if (visited[curr]) continue;
        visited[curr] = true;

        for (auto [v, w] : adj[curr]) {
            if (dist[curr] + w < dist[v]) {
                dist[v] = dist[curr] + w;
                q.push({-dist[v], v});
            }
        }
    }

    return dist;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    adjA.assign(n+1, vector<pll>());
    adjB.assign(n+1, vector<pll>());

    ll a, b, c;
    vector <tuple <ll,ll,ll>> no;
    while (m--) {
        cin >> a >> b >> c;
        
        no.push_back({a,b,c});
        adjA[a].push_back({b,c});
        adjB[b].push_back({a,c});
    }
    vector <ll> distA = dijkstra(1, adjA);
    vector <ll> distB = dijkstra(n, adjB);

    ll ans = INF;
    for (auto [a,b,w] : no)
        ans = min(ans, distA[a] + distB[b] + w/2);

    cout << ans << "\n";

    return 0;
}