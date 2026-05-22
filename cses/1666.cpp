/*
 * Contest : CSES Problem Set
 * Problem : 1666 - Building Roads
 * Link    : https://cses.fi/problemset/task/1666
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

const int N = 1e5 + 1;
vector<int> graph[N], visited(N), roads;

void dfs(int u) {
  visited[u] = 1;
  for (auto &v : graph[u])
    if (!visited[v]) dfs(v);
}

int main() {
  fastio

  int n, m;
  cin >> n >> m;
  while (m--) {
    int a, b;
    cin >> a >> b;

    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  for (int i = 1; i <= n; ++i)
    if (!visited[i]) {
      roads.push_back(i);
      dfs(i);
    }
  cout << roads.size() - 1 << '\n';
  for (int i = 1; i < roads.size(); ++i) cout << roads[i - 1] << ' ' << roads[i] << '\n';

  return 0;
}
