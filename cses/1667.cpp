/**
 * Contest : CSES Problem Set
 * Problem : 1667 - Message Route
 * Link    : https://cses.fi/problemset/task/1667
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

const int N = 1e5 + 1;
vector<int> graph[N], dist(N), p(N);

void bfs(int src = 1) {
  queue<int> q;
  q.push(src);
  dist[src] = 1;
  while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (auto &v : graph[u]) {
      if (!dist[v]) {
        dist[v] = dist[u] + 1;
        p[v] = u;
        q.push(v);
      }
    }
  }
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

  bfs();
  if (!dist[n]) cout << "IMPOSSIBLE\n";
  else {
    cout << dist[n] << '\n';
    vector<int> path;
    for (int i = n; i > 0; i = p[i]) path.push_back(i);
    for (int i = path.size() - 1; i >= 0; --i) cout << path[i] << " \n"[!i];
  }

  return 0;
}
