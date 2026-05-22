/*
 * Contest : CSES Problem Set
 * Problem : 1193 - Labyrinth
 * Link    : https://cses.fi/problemset/task/1193
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);
using pii = pair<int, int>;

const int MAX = 1001;
int n, m;
int grid[MAX][MAX];

void bfs(pii st) {
  queue<pii> q;
  q.push(st);

  while (!q.empty()) {
    auto [i, j] = q.front();
    q.pop();

    for (auto d : {1, -1}) {
      int x = d + i, y = d + j;
      if (x >= 0 && x < n && grid[x][j] == 0) {
        grid[x][j] = grid[i][j] + 1;
        q.push({x, j});
      }
      if (y >= 0 && y < m && grid[i][y] == 0) {
        grid[i][y] = grid[i][j] + 1;
        q.push({i, y});
      }
    }
  }
  grid[st.first][st.second] = 0;
}

stack<char> getPath(pii end) {
  stack<char> st;
  auto [i, j] = end;

  while (grid[i][j] != 0) {
    int curr = grid[i][j];

    for (auto d : {1, -1}) {
      int x = d + i, y = d + j;

      if (x >= 0 && x < n && grid[x][j] == curr - 1) {
        st.push(d == 1 ? 'U' : 'D');
        i = x;
      }
      if (y >= 0 && y < m && grid[i][y] == curr - 1) {
        st.push(d == 1 ? 'L' : 'R');
        j = y;
      }
    }
  }
  return st;
}

int main() {
  fastio

  cin >> n >> m;
  pii a, b;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      char c; cin >> c;
      if (c == 'A')
        a = {i, j};
      if (c == 'B')
        b = {i, j};

      if (c == '#') grid[i][j] = -1;
      else
        grid[i][j] = 0;
    }
  }
  bfs(a);

  if (!grid[b.first][b.second]) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
    cout << grid[b.first][b.second] << '\n';

    auto path = getPath(b);
    while (!path.empty()) {
      cout << path.top();
      path.pop();
    }
    cout << '\n';
  }

  return 0;
}
