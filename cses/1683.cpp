/**
 * Contest : CSES Problem Set
 * Problem : 1683 - Planets and Kingdoms
 * Link    : https://cses.fi/problemset/task/1683
 * Time    : O(N + M)
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

const int N = 1e5+1;
vector<vector<int>> adj, revAdj;
vector<int> order, comp;
bitset<N> visited;
int n, m;

void topo(int u) {
  visited[u] = true;
  for(auto& v : adj[u])
    if (!visited[v]) topo(v);
  order.push_back(u);
}

void dfs(int u, int id) {
  visited[u] = true;
  comp[u] = id;
  for(auto& v : revAdj[u])
    if (!visited[v]) dfs(v, id);
}

int main() {
  fastio

  cin >> n >> m;
  adj.assign(n+1, {});
  revAdj.assign(n+1, {});
  comp.assign(n+1, -1);

  while (m--) {
    int a, b;
    cin >> a >> b;

    adj[a].push_back(b);
    revAdj[b].push_back(a);
  }

  for (int i = 1; i <= n; ++i)
    if (!visited[i]) topo(i);
  reverse(order.begin(), order.end());

  visited.reset();
  int id = 0;
  for (auto& u : order) 
    if (!visited[u]) 
      dfs(u, ++id);

  cout << id << '\n';
  for (int i = 1; i <= n; ++i)
    cout << comp[i] << ' ';
  cout << '\n';

  return 0;
}