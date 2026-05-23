/**
 * Contest : CSES Problem Set
 * Problem : 1681 - Game Routes
 * Link    : https://cses.fi/problemset/task/1681
 * Time    : O(N + M)
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int n, m;
vector<vector<int>> graph;
vector<int> deg, visited, order;

void dfs(int u) {
  visited[u] = true;
  for (auto& v : graph[u]) 
    if (!visited[v]) 
      dfs(v);
  order.push_back(u);
}

int main() {
  fastio

  const int MOD = 1e9+7;
  cin >> n >> m;
  graph.assign(n+1, {});
  deg.assign(n+1, 0);
  visited.assign(n+1, false);

  while (m--) {
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
  }
  
  dfs(1);
  reverse(order.begin(), order.end());
  deg[1] = 1;
  for (auto u : order) 
    for (auto& v : graph[u]) 
      deg[v] = (deg[v] + deg[u]) % MOD;

  cout << deg[n] << '\n';

  return 0;
}