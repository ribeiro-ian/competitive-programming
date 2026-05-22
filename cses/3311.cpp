/*
 * Contest : CSES Problem Set
 * Problem : 3311 - Grid Coloring I
 * Link    : https://cses.fi/problemset/task/3311
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

vector<string> grid(505), ans(505);
int n, m;

void change(int i, int j) {
  char ch = grid[i][j];

  for (char l = 'A'; l <= 'D'; ++l) {
    if (ch == l) continue;

    bool flag = true;
    for (auto &d : {1, -1}) {
      int x = i + d, y = j + d;

      if (x >= 0 && x < n && ans[x][j] == l) {
        flag = false;
        break;
      }
      if (y >= 0 && y < m && ans[i][y] == l) {
        flag = false;
        break;
      }
    }

    if (flag) {
      ans[i][j] = l;
      return;
    }
  }
}

int main() {
  fastio

  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> grid[i];
    ans[i] = string(m, '-'); // init matrix 'ans'
  }

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; ++j) change(i, j);

  for (int i = 0; i < n; i++) cout << ans[i] << '\n';

  return 0;
}
