/*
 * Contest : CSES 
 * Problem : 1675 - Road Reparation
 * Link    : https://cses.fi/problemset/task/1675
 * Time    : O(?)
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int n, m;
struct Edge {ll a,b, c;};
vector<Edge> edges;

ll kruskal() {
  sort(edges.begin(), edges.end(), [](auto a, auto b){
    return a.c < b.c;
  });

  ll sum = 0;
  vector<bool> visited(n+1, false);
  for (auto& e : edges) {
    if (visited[e.a] && visited[e.b]) continue;
    visited[e.a] = visited[e.b] = true;
    sum += e.c;
  }

  return sum;
}

int main() {
  fastio

  cin >> n >> m;
  while (m--) {
    Edge e;
    cin >> e.a >> e.b >> e.c;
    edges.emplace_back(e);
  }

  cout << kruskal() << '\n';

  return 0;
}
