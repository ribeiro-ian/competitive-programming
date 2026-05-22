/*
 * Contest : CSES Problem Set
 * Problem : 1624 - Chessboard and Queens
 * Link    : https://cses.fi/problemset/task/1624
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

const int n = 8;
vector<int> col(n), diag1(2 * n), diag2(2 * n);
vector<string> grid(n);
ll ans = 0;

void back(int y) {
  if (y == n) {
    ans++;
    return;
  }
  for (int x = 0; x < n; ++x) {
    // y = row; x = col
    if (col[x] || diag1[x + y] || diag2[x - y + n] || grid[y][x] == '*') continue;

    col[x] = diag1[x + y] = diag2[x - y + n] = 1;
    back(y + 1);
    col[x] = diag1[x + y] = diag2[x - y + n] = 0;
  }
}

int main() {
  fastio

  for (auto &i : grid) cin >> i;

  back(0);
  cout << ans << '\n';

  return 0;
}
