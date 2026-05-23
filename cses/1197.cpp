/**
 * Contest : CSES Problem Set
 * Problem : 1197 - Cycle Finding
 * Link    : https://cses.fi/problemset/task/1197
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

const ll INF = 1e18;
struct Edge {
  int a, b, c;
};
vector<Edge> edges;
vector<ll> d, p;
int n, m;

bool bellman_ford() {
  d.assign(n+1, 0);
  p.assign(n+1, -1);
  
  ll cycle;
	for (int i = 0; i < n; ++i) {
    cycle = -1;
    for (Edge e : edges) {
      if (d[e.a] < INF && d[e.b] > d[e.a] + e.c) {
        d[e.b] = d[e.a] + e.c;
        p[e.b] = e.a;
        cycle = e.b;
      }
    }
  }

  if (cycle == -1) return false;

  cout << "YES\n";
  for (int i = 0; i < n; ++i) cycle = p[cycle];

  stack<ll> path;
  for (ll cur = cycle;; cur = p[cur]) {
    path.push(cur);
    if (cur == cycle && path.size() > 1)
      break;
  }
  while (!path.empty()) {
    cout << path.top() << ' ';
    path.pop();
  }
  cout << '\n';

  return true;
}

int main() {
  fastio

  cin >> n >> m;
  edges.resize(m);
  for (auto& i : edges)
    cin >> i.a >> i.b >> i.c;
  
  if (!bellman_ford())
    cout << "NO\n";

  return 0;
}
