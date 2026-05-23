/**
 * Contest : CSES 
 * Problem : 1675 - Road Reparation
 * Link    : https://cses.fi/problemset/task/1675
 * Time    : O((N + M) * logN)
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

vector<vector<pair<ll,ll>>> adj;
int n, m;

ll prim() {
  priority_queue<pair<ll,ll>> pq;
  pq.emplace(0,1);

  bitset<10'001> visited;
  ll sum = 0;
  while (!pq.empty()) {
    auto [w, u] = pq.top();
    pq.pop();

    if (visited[u]) continue;

    sum += -w;
    visited[u] = true;

    for (auto& [v,w] : adj[u]) 
      if (!visited[v]) 
        pq.emplace(-w, v);
  }
  return visited[n]? sum : -1;
}

int main() {
  fastio

  cin >> n >> m;
  adj.assign(n+1, {});
  while (m--) {
    ll a, b, c;
    cin >> a >> b >> c;
    adj[a].emplace_back(b,c);
    adj[b].emplace_back(a,c);
  }

  ll ans = prim();
  if (ans != -1)
    cout << ans << '\n';
  else
    cout << "IMPOSSIBLE\n";

  return 0;
}
