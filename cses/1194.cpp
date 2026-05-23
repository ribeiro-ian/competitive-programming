/**
 * Contest : CSES Problem Set
 * Problem : 1194 - Monsters
 * Link    : https://cses.fi/problemset/task/1194
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);
using pii = pair<int, int>;

const int N = 1'000 + 1;
int you[N][N], monster[N][N], n, m;
char grid[N][N];

set<pii> exits;
queue<pii> q;

pii bfs(pii a) {
  queue<pii> q;
  q.push(a);

  while (!q.empty()) {
    auto [i, j] = q.front();
    q.pop();
    if (exits.count({i, j}))
      return {i, j};

    int curr = you[i][j];
    for (auto d : {1, -1}) {
      int x = d + i, y = d + j;

      if (x >= 0 && x < n && grid[x][j] != '#' && you[x][j] == -1 && curr + 1 < monster[x][j]) {
        q.push({x, j});
        you[x][j] = curr + 1;
      }
      if (y >= 0 && y < m && grid[i][y] != '#' && you[i][y] == -1 && curr + 1 < monster[i][y]) {
        q.push({i, y});
        you[i][y] = curr + 1;
      }
    }
  }

  return {-1, -1};
}

void bfsMonster() {
  while (!q.empty()) {
    auto [i, j] = q.front();
    q.pop();

    int curr = monster[i][j];
    for (auto d : {1, -1}) {
      int x = d + i, y = d + j;

      if (x >= 0 && x < n && grid[x][j] != '#' && curr + 1 < monster[x][j]) {
        q.push({x, j});
        monster[x][j] = curr + 1;
      }
      if (y >= 0 && y < m && grid[i][y] != '#' && curr + 1 < monster[i][y]) {
        q.push({i, y});
        monster[i][y] = curr + 1;
      }
    }
  }
}

stack<char> getPath(pii b) {
  stack<char> st;
  auto [i, j] = b;

  while (you[i][j] != 0) {
    int curr = you[i][j];
    for (auto d : {1, -1}) {
      int x = d + i, y = d + j;

      if (x >= 0 && x < n && you[x][j] == curr - 1) {
        st.push(d == 1 ? 'U' : 'D');
        i = x;
      } else if (y >= 0 && y < m && you[i][y] == curr - 1) {
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

  pii a;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      char c; cin >> c;
      grid[i][j] = (c == '#' ? '#' : '.');

      you[i][j] = -1;
      monster[i][j] = 1e9;

      if (c == 'A') {
        you[i][j] = 0;
        a = {i, j};
      }
      if (c == 'M') {
        monster[i][j] = 0;
        q.push({i, j});
      }

      if (c != '#' && (i == 0 || i == n - 1) && (j != 0 && j != n - 1))
        exits.insert({i, j});
      if (c != '#' && (j == 0 || j == m - 1) && (i != 0 && i != n - 1))
        exits.insert({i, j});
      if (c != '#' && (n <= 2 || m <= 2))
        exits.insert({i, j});
    }
  }

  bfsMonster();
  pii b = bfs(a);

  if (b.first == -1) cout << "NO\n";
  else {
    cout << "YES\n";

    stack<char> path;
    if (b != a) path = getPath(b);

    cout << path.size() << '\n';
    while (!path.empty()) {
      cout << path.top();
      path.pop();
      if (path.empty()) cout << '\n';
    }
  }

  return 0;
}