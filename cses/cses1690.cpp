/*
 * Contest : CSES
 * Problem : 1690 - Hamiltonian Flights
 * Link    : https://cses.fi/problemset/task/1690
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);
const ll M = 1e9 + 7;

int n, m;
vector<int> dp;
vector<vector<bool>> graph;

void dfs(int mask, int ant) {

  for (int i = 1; i < n; ++i) {
    if (mask & (1 << i)) continue;

    if (graph[ant][i]) { dfs(mask | (1 << i), i); }
  }
}

int main() {
  fastio

  cin >> n >> m;

  graph.assign(n, vector<bool>(n, false));
  while (m--) {
    int a, b;
    cin >> a >> b;
    graph[--a][--b] = true;
  }

  dfs(1, 1);

  cout << dp[(1 << n) - 1] << endl;

  return 0;
}