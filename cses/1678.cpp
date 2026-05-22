/*
 * Contest : CSES Problem Set
 * Problem : 1678 - Round Trip II
 * Link    : https://cses.fi/problemset/task/1678
 * Time    : O(N + M)
 */

#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int n, m;
vector<vector<int>> graph;
vector<int> visited, processing, cycle;

bool dfs(int u) {
  if (processing[u] && cycle.empty()) {
    cycle.push_back(u);
    return cycle.size() == 1;
  }
  if (visited[u]) return false;

  visited[u] = true;
  processing[u] = true;

  for (auto& v : graph[u]) {
    if (dfs(v)) {
      cycle.push_back(u);
      return cycle.back() != cycle.front();
    }
  }

  processing[u] = false;

  return false;
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
    if (dfs(i)) break;
  
  if (cycle.size()) {
    cout << cycle.size() << '\n';
    reverse(cycle.begin(), cycle.end());

    for (auto& i : cycle)
      cout << i << ' ';
    cout << '\n';
  }
  else
    cout << "IMPOSSIBLE\n";

  return 0;
}