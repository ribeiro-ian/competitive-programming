/**
 * Contest : CSES Problem Set
 * Problem : 1131 - Tree Diameter
 * Link    : https://cses.fi/problemset/task/1131
 * Time    : O(N)
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

vector<vector<int>> tree;
vector<int> dist;

void dfs(int u, int p, int d) {
  dist[u] = d;
  for (auto& v : tree[u]) {
    if (v == p) continue;
    dfs(v, u, d+1);
  }
}

int main() {
  fastio

  int n; cin >> n;
  tree.assign(n+1, {});
  dist.assign(n+1, 0);

  for (int i = 2; i <= n; ++i) {
    int a, b;
    cin >> a >> b;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }

  dfs(1, 1, 0);
  auto farthest = max_element(dist.begin()+1, dist.end()) - dist.begin();

  dist.assign(n+1, 0);
  dfs(farthest, farthest, 0);

  cout << *max_element(dist.begin()+1, dist.end()) << '\n';

  return 0;
}