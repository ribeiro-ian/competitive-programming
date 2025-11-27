/*
    CSES 1673 - High Score
    https://cses.fi/problemset/task/1673
*/
 
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
 
const ll INF = 1e18;

vector <vector <ll>> graph;
vector <vector<ll>> adj;
vector <ll> loop;
vector <bool> visited;
ll n, m;
 
ll bellmanFord(int src = 1) {
	vector<ll> dist(n+1, -INF);
	dist[src] = 0;
  
	for (int i = 0; i < n; i++) {
		for (auto &edge : graph) {
			ll u = edge[0], v = edge[1], w = edge[2];

			if (dist[u] != -INF && dist[u] + w > dist[v]) {
                dist[v] = dist[u] + w;

                if (i == n-1) 
                    loop.push_back(v);
            }
		}
	}

    return dist[n];
}

bool dfs(int i) {
    visited[i] = true;
    if (i == n) return true;

    for (auto &v : adj[i]) {
        if (!visited[v]) {
            bool flag = dfs(v); 
            if (flag) return flag;
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
 
    cin >> n >> m; 
    adj.resize(n+1);
    while (m--) {
        ll a, b, c;
        cin >> a >> b >> c;
        graph.push_back({a,b,c});
        adj[a].push_back(b);
    }
 
    ll ans = bellmanFord();

    visited.assign(n+1, false);
    for (auto &i : loop) {
        if (!visited[i]) {
            if (dfs(i)) {
                cout << -1 << '\n';
                return 0;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}