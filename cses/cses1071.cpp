/*
 * Contest : CSES
 * Problem : 1071 - Number Spiral
 * Link    : https://cses.fi/problemset/task/1071
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  int tc; cin >> tc;

  while (tc--) {
    ll row, col, ans = 0;
    cin >> row >> col;

    if (row >= col) {
      if (row % 2 == 0) ans = row * row - col + 1;
      else
        ans = (row - 1) * (row - 1) + col;
    } else if (col > row) {
      if (col % 2 == 1) ans = col * col - row + 1;
      else
        ans = (col - 1) * (col - 1) + row;
    }
    cout << ans << '\n';
  }

  return 0;
}