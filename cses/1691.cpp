/**
 * Contest : CSES Problem Set
 * Problem : 1691 - Mail Delivery
 * Link    : https://cses.fi/problemset/task/1691
 * Time    : O(N + M)
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

vector<vector<pair<int,int>>> adj;
vector<bool> used;
int n, m;

bool hasEulerCycle() {
  int ini = 1;

  for (int i = 1; i <= n; i++) {
    if (adj[i].size() & 1)
      return 0;
  }

  vector<int> ptr(n+1, 0);
  stack<int> st;
  vector<int> path;
  st.push(ini);

  while (!st.empty()) {
    int u = st.top();
    while (ptr[u] < (int)adj[u].size() && used[adj[u][ptr[u]].second])
      ptr[u]++;
    if (ptr[u] < (int)adj[u].size()) {
      auto [v, id] = adj[u][ptr[u]++];
      used[id] = true;
      st.push(v);
    }
    else {
      path.push_back(u);
      st.pop();
    }
  }

  for (int i = 0; i < m; i++)
    if (!used[i]) return 0;

  reverse(path.begin(), path.end());
  for (auto i : path) cout << i << ' ';
  cout << '\n';

  return 1;
}

int main() {
  fastio

  cin >> n >> m;
  adj.assign(n+1, {});
  used.assign(m, false);
  int id = 0;

  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back({b,id});
    adj[b].push_back({a,id++});
  }

  if (!hasEulerCycle()) cout << "IMPOSSIBLE\n";

  return 0;
}