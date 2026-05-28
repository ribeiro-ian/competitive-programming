/**
 * Contest : CSES Problem Set
 * Problem : 1133 - Tree Distances II
 * Link    : https://cses.fi/problemset/task/1133
 * Time    : O(???)
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

vector<vector<int>> tree;
vector<int> d1, d2;

void dfs(int u, int p, int d, vector<int>& dist) {
  dist[u] = d;
  for (auto& v : tree[u]) {
    if (v == p) continue;
    dfs(v, u, d+1, dist);
  }
}

int main() {
  fastio

  int n; cin >> n;
  tree.assign(n+1, {});

  for (int i = 2; i <= n; ++i) {
    int a, b;
    cin >> a >> b;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }

  d1.assign(n+1, 0);
  dfs(1, 1, 0, d1);
  
  int farthest = max_element(d1.begin()+1, d1.end()) - d1.begin();
  d1.assign(n+1, 0);
  dfs(farthest, farthest, 0, d1);

  farthest = max_element(d1.begin()+1, d1.end()) - d1.begin();
  d2.assign(n+1, 0);
  dfs(farthest, farthest, 0, d2);

  for (int i = 1; i <= n; i++)
    cout << max(d1[i], d2[i]) << " \n"[i==n];

  return 0;
}