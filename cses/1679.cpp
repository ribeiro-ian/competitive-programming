/*
 * Contest : CSES Problem Set
 * Problem : 1679 - Course Schedule
 * Link    : https://cses.fi/problemset/task/1679
 * Time    : O(N + M)
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int n, m;
vector<vector<int>> graph;
vector<int> visited, processing, order;
bool hasCycle = false;

void dfs(int u) {
  visited[u] = true;
  processing[u] = true;

  for (auto& v : graph[u]) {
    if (processing[v]) {
      hasCycle = true;
      return;
    }
    if (!visited[v]) 
      dfs(v);
  }

  processing[u] = false;
  order.push_back(u);
}

int main() {
  fastio

  cin >> n >> m;
  graph.assign(n+1, {});
  visited.assign(n+1, false);
  processing.assign(n+1, false);

  while (m--) {
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
  }
  
  for (int i = 1; i <= n; ++i)
    if (!visited[i]) dfs(i);
  
  if (!hasCycle) {
    reverse(order.begin(), order.end());
    for (auto& i : order)
      cout << i << ' ';
    cout << '\n';
  }
  else
    cout << "IMPOSSIBLE\n";

  return 0;
}