/*
 * Contest : CSES Problem Set
 * Problem : 1195 - Flight Discount
 * Link    : https://cses.fi/problemset/task/1195
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using no = pair<ll,ll>;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

ll n, m;
void dijkstra(ll src, vector<ll>& dist, vector<vector<no>>& graph) {
	dist.assign(n+1, 1e18);
	priority_queue<no> q;
	q.push({0, src});
  dist[src] = 0;

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
  vector<vector<no>> graph(n+1), rev_graph(n+1);
  vector<ll> distFrom1(n+1), distToN(n+1);
  vector<tuple<ll,ll,ll>> flights;

  while (m--) {
    ll a, b, c;
    cin >> a >> b >> c;

    graph[a].push_back({b,c});
    rev_graph[b].push_back({a,c});
    flights.push_back({a,b,c});
  }

  dijkstra(1, distFrom1, graph);
  dijkstra(n, distToN, rev_graph);

  ll ans = 1e18;
  for (auto& [a,b,c] : flights)
    ans = min(ans, distFrom1[a] + c/2 + distToN[b]);
  cout << ans << '\n';

  return 0;
}
