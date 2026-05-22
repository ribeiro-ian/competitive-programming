/*
 * Contest : CSES Problem Set
 * Problem : 3217 - Knight Moves Grid
 * Link    : https://cses.fi/problemset/task/3217
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

const int N = 1001;
vector<int> dir1 = {1, -1};
vector<int> dir2 = {2, -2};
queue<pair<int, int>> q;

int grid[N][N];

void add(int val, int x, int y) {
  if (grid[x][y] == -1) {
    grid[x][y] = val + 1;
    q.push({x, y});
  }
}

int main() {
  fastio
  memset(grid, -1, sizeof(grid));

  int n; cin >> n;
  grid[0][0] = 0;
  q.push({0, 0});

  while (!q.empty()) {
    auto [row, col] = q.front();
    q.pop();
    int val = grid[row][col];

    for (auto &d1 : dir1) {
      for (auto &d2 : dir2) {
        int x = row + d1,
            y = col + d2;

        if (x < n && x >= 0 && y < n && y >= 0) {
          add(val, x, y);
          add(val, y, x);
        }

        x = row + d2;
        y = col + d1;

        if (x < n && x >= 0 && y < n && y >= 0) {
          add(val, x, y);
          add(val, y, x);
        }
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) { cout << grid[i][j] << ' '; }
    cout << '\n';
  }

  return 0;
}
