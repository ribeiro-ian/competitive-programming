/*
 * Contest : Codeforces
 * Problem : 1315A - Dead Pixel
 * Link    : https://codeforces.com/problemset/problem/1315/A
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

void solve() {
  int a, b, x, y;
  cin >> a >> b >> x >> y;

  cout << max(max(x, a - 1 - x) * b, max(y, b - 1 - y) * a) << "\n";
}

int main() {
  fastio

  int tc; cin >> tc;
  while (tc--) { solve(); }

  return 0;
}