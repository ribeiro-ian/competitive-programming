/*
 * Contest : CSES Problem Set
 * Problem : 1669 - Round Trip
 * Link    : https://cses.fi/problemset/task/1669
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

const int N = 1e5 + 1;
vector<int> graph[N], cycle, visited(N);

bool dfs(int u, int p) {
  if (visited[u]) {
    if (cycle.empty()) cycle.push_back(u);
    return cycle.size() == 1;
  }
  visited[u] = 1;

  for (auto &v : graph[u]) {
    if (v != p && dfs(v, u)) {
      cycle.push_back(u);
      return (cycle.front() != cycle.back());
    }
  }
  return false;
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
    if (!visited[i] && dfs(i, i)) break;

  if (!cycle.size()) {
    cout << "IMPOSSIBLE\n";
  } else {
    cout << cycle.size() << '\n';
    for (auto &i : cycle) cout << i << ' ';
    cout << '\n';
  }

  return 0;
}
