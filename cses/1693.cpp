/**
 * Contest : CSES Problem Set
 * Problem : 1693 - Teleporters Path
 * Link    : https://cses.fi/problemset/task/1693
 * Time    : O(N + M)
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

vector<vector<int>> adj;
vector<int> in, out;
int n, m;

bool hasEulerPath() {
  int ini = 1, fim = n;
  if (out[ini]-in[ini] != 1 || in[fim]-out[fim] != 1) return 0;

  for (int i = 2; i <= n-1; i++)
    if (in[i] != out[i]) return 0;

  // Algoritmo de Hierholzer
  stack<int> st;
  vector<int> path;
  st.push(ini);

  while (!st.empty()) {
    int u = st.top();
    if (!adj[u].empty()) {
      int v = adj[u].back();
      adj[u].pop_back();
      st.push(v);
    }
    else {
      path.push_back(u);
      st.pop();
    }
  }

  for (int i = 1; i <= n; i++)
    if (!adj[i].empty()) return 0;
  if (path.front() != n) return 0;

  reverse(path.begin(), path.end());
  for (auto& i : path) cout << i << ' ';
  cout << '\n';

  return 1;
}

int main() {
  fastio

  cin >> n >> m;

  in.assign(n+1, 0);
  out.assign(n+1, 0);
  adj.assign(n+1, {});

  while (m--) {
    int a, b;
    cin >> a >> b;

    adj[a].push_back(b);
    out[a]++;
    in[b]++;
  }
  if (!hasEulerPath()) cout << "IMPOSSIBLE\n";

  return 0;
}