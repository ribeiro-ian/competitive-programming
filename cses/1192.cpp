/*
 * Contest : CSES Problem Set
 * Problem : 1192 - Counting Rooms
 * Link    : https://cses.fi/problemset/task/1192
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

const int MAX = 1001;
int n, m;
char grid[MAX][MAX];

void dfs(int i, int j) {
  grid[i][j] = '-';
  for (auto d : {1, -1}) {
    int x = d + i, y = d + j;
    if (x >= 0 && x < n && grid[x][j] == '.') dfs(x, j);
    if (y >= 0 && y < m && grid[i][y] == '.') dfs(i, y);
  }
}

int main() {
  fastio

  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) cin >> grid[i][j];

  int cnt = 0;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if (grid[i][j] == '.') {
        cnt++;
        dfs(i, j);
      }
  cout << cnt << '\n';

  return 0;
}
