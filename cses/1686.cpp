/**
 * Contest : CSES Problem Set
 * Problem : 1686 - Coin Collector
 * Link    : https://cses.fi/problemset/task/1686
 * Time    : O(N + M) 
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

vector<vector<ll>> adj, revAdj;
vector<ll> c, order;
bitset<10'0001> visited;
ll n, m, sum;

void topo(int u) {
  visited[u] = true;
  for (auto& v : adj[u])
    if (!visited[v])
      topo(v);
  order.push_back(u);
}

void dfs(int u) {
  visited[u] = true;
  sum += c[u];
  for (auto& v : revAdj[u])
    if (!visited[v])
      dfs(v);
}

int main() {
  fastio

  cin >> n >> m;
  c.assign(n+1, -1);
  adj.assign(n+1, {});
  revAdj.assign(n+1, {});

  for (int i = 1; i <= n; ++i) cin >> c[i];

  while (m--) {
    ll a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    revAdj[b].push_back(a);
  }

  for (int i = 1; i <= n; ++i)
    if (!visited[i])
      topo(i);
  reverse(order.begin(), order.end());
  visited.reset();

  ll maxi = 0;
  for (auto& u : order) 
    if (!visited[u]) {
      sum = 0;
      dfs(u);
      maxi = max(maxi, sum);
    }
  cout << maxi << '\n';

  return 0;
}