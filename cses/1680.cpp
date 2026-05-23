/**
 * Contest : CSES Problem Set
 * Problem : 1680 - Longest Flight Route
 * Link    : https://cses.fi/problemset/task/1680
 * Time    : O(N + M)
 */

#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int n, m;
vector<vector<int>> graph;
vector<int> d, p, visited, order;

void dfs(int u) {
  visited[u] = true;
  for (auto& v : graph[u]) 
    if (!visited[v]) 
      dfs(v);
  order.push_back(u);
}

int main() {
  fastio

  cin >> n >> m;
  graph.assign(n+1, {});
  d.assign(n+1, 0);
  p.assign(n+1, -1);
  visited.assign(n+1, false);

  while (m--) {
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
  }
  
  dfs(1);
  reverse(order.begin(), order.end());
  d[1] = 1;
  for (auto u : order) {
    if (d[u]) 
      for (auto& v : graph[u]) 
        if (d[u]+1 > d[v]) {
          d[v] = d[u]+1;
          p[v] = u;
        }
  }

  if (d[n]) {
    cout << d[n] << '\n';

    vector<int> path;
    for (int cur = n; cur != -1; cur = p[cur]) 
      path.push_back(cur);
    
    reverse(path.begin(), path.end());
    for (auto& i : path) cout << i << ' ';
    cout << '\n';
  }
  else
    cout << "IMPOSSIBLE\n";

  return 0;
}