/*
 * Contest : UVA
 * Problem : 657 - The die is cast
 * Link    : https://vjudge.net/problem/UVA-657
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

string grid[51];
pair<int, int> dir[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int h, w, caseNum = 0;

void dfsX(int i, int j) {
  grid[i][j] = '*';
  for (auto d : dir) {
    int dx = d.first, dy = d.second;
    int x = dx + i, y = dy + j;

    if (x >= 0 && x < h && y >= 0 && y < w && grid[x][y] == 'X') dfsX(x, y);
  }
}

void dfs(int i, int j, int &cnt) {
  grid[i][j] = '.';
  for (auto d : dir) {
    int dx = d.first, dy = d.second;
    int x = dx + i, y = dy + j;

    if (x >= 0 && x < h && y >= 0 && y < w) {
      if (grid[x][y] != '.') {
        if (grid[x][y] == 'X') {
          dfsX(x, y);
          cnt++;
        }
        dfs(x, y, cnt);
      }
    }
  }
}

int main() {
  fastio

  while (cin >> w >> h, w && h) {
    vector<int> num;

    for (int i = 0; i < h; ++i) cin >> grid[i];

    for (int i = 0; i < h; ++i)
      for (int j = 0; j < w; ++j)
        if (grid[i][j] != '.') {
          num.push_back(0);
          dfs(i, j, num[num.size() - 1]);
        }

    sort(num.begin(), num.end());
    cout << "Throw " << ++caseNum << '\n';
    for (int i = 0; i < num.size(); ++i) cout << num[i] << " \n"[i == num.size() - 1];
    cout << '\n';
  }

  return 0;
}