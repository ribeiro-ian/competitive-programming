/**
 * Contest : CSES Problem Set
 * Problem : 1671 - Shortest Routes I
 * Link    : https://cses.fi/problemset/task/1671
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

const ll N = 1e5+1, INF = 1e18;
vector<pair<ll,ll>> graph[N];
vector<ll> dist;
ll n, m;

void dijkstra() {
	dist.assign(n+1, INF);
	priority_queue<pair<ll,ll>> q;
	q.push({0, 1});
  dist[1] = 0;

	while (!q.empty()) {
    auto [du, u] = q.top();
    q.pop();
    if (-du > dist[u]) continue;

    for (auto& [v,w] : graph[u]) {
      if (dist[u] + w < dist[v]) {
        dist[v] = dist[u] + w;
        q.push({-dist[v], v});
      }
    }
  }
}

int main() {
	fastio

	cin >> n >> m;
	while (m--) {
    ll a, b, c;
    cin >> a >> b >> c;
    graph[a].push_back({b,c});
  }

	dijkstra();
	for (int i = 1; i <= n; ++i)
    cout << dist[i] << " \n"[i==n];

	return 0;
}