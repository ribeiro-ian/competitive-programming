/*
    CSES 1202 - Investigation
    https://cses.fi/problemset/task/1202
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;

vector <vector <pll>> adj;
const ll INF = 1e18, mod = 1e9+7;
vector <ll> dist, weight;
ll n, m;
ll cnt, minimum, maximum;

void dijkstra(ll no) {
    vector <bool> visited(n+1, false);
    dist.assign(n+1, INF);
    weight.assign(n+1, 0);
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
                q.push({-dist[v], v});
                dist[v] = dist[curr] + w;
                
                cnt = 1;
                weight[v] = minimum = maximum = weight[curr] + 1;
            }
            else if (dist[curr] + w == dist[v]) {
                q.push({-dist[v], v});
                cnt++;
                minimum = min(minimum, weight[curr]+1);
                maximum = max(maximum, weight[curr]+1);
            }
        }
    }
    minimum = min(minimum, weight[n]);
    maximum = max(maximum, weight[n]);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    adj.assign(n+1, vector<pll>());

    ll a, b, c;
    while (m--) {
        cin >> a >> b >> c;

        adj[a].push_back({b,c});
    }

    cnt = 0, minimum = INF, maximum = 0;
    dijkstra(1);
    
    cout << dist[n] << " " << cnt <<
    " " << minimum << " " << maximum << "\n";

    for (int i = 1; i<=n; ++i)
        cerr << dist[i] << " "; cerr << "\n";

    return 0;
}