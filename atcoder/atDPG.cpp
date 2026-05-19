/*
 * Contest : AtCoder Educational DP Contest
 * Problem : G - Longest Path
 * Link    : https://atcoder.jp/contests/dp/tasks/dp_g
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

vector<vector<int>> adj;
vector<int> dist;

int dfs(int no) {
  if (dist[no]) return dist[no];

  int longest = 0;
  for (auto &v : adj[no]) longest = max(longest, dfs(v));

  return dist[no] = longest + 1;
}

int main() {
  fastio

  int n, m;
  cin >> n >> m;

  adj.resize(n + 1);
  dist.assign(n + 1, false);

  while (m--) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
  }

  int ans = 0;
  for (int i = 1; i <= n; ++i) ans = max(ans, dfs(i));
  cout << ans - 1 << '\n';

  return 0;
}