/*
    CSES 1673 - High Score
    https://cses.fi/problemset/task/1673
*/
 
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
 
const ll INF = 1e18;

vector <vector<ll>> adj;
vector <ll> loop;
vector <bool> visited;

bool flag = false;
vector <vector <ll>> graph;
ll n, m;
 
ll bellmanFord(int src) {
	vector<ll> dist(n+1, -INF);
	dist[src] = 0;
  
	for (int i = 0; i < n; i++) {
		for (auto &edge : graph) {
			ll u = edge[0];
			ll v = edge[1];
			ll w = edge[2];
			if (dist[u] != -INF && dist[u] + w > dist[v]) {
                dist[v] = dist[u] + w;

                if (i == n-1) {
                    loop.push_back(u);
                    loop.push_back(v);
                }
            }
		}
	}

    return dist[n];
}

void dfs(int i) {
    visited[i] = true;
    if (i==n) flag = true;

    for (auto &v : adj[i]) {
        if (!visited[v])
            dfs(v);
    }
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
 
    ll ans = bellmanFord(1);

    visited.assign(n+1, false);
    for (auto &i : loop) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    cout << (flag ? -1 : ans) << endl;

    return 0;
}