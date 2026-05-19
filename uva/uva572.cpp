/*
 * Contest : UVA
 * Problem : 572 - Oil Deposits
 * Link    : https://vjudge.net/problem/UVA-572
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

string grid[101];
int dir[] = {-1, 0, 1}, n, m;

void dfs(int i, int j) {
  grid[i][j] = 'X';
  for (auto &x : dir) {
    for (auto &y : dir) {
      int lin = i + x, col = j + y;
      if (lin >= 0 && lin < n && col >= 0 && col < m && grid[lin][col] == '@') dfs(lin, col);
    }
  }
}

void solve() {
  for (int i = 0; i < n; ++i) cin >> grid[i];

  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (grid[i][j] == '@') {
        dfs(i, j);
        cnt++;
      }
    }
  }
  cout << cnt << '\n';
}

int main() {
  fastio

  while (cin >> n >> m, n && m) solve();

  return 0;
}