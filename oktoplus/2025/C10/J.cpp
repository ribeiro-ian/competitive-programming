/*
  Codeforces 1315A - Dead Pixel
  https://codeforces.com/problemset/problem/1315/A
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

void solve() {
  int a, b, x, y;
  cin >> a >> b >> x >> y;

  x++, y++;
  cout << max(y, b - y) * a << " ";
  cout << max(x, a - x) * b << "\n";
}

int main() {
  fastio

  int tc; cin >> tc;
  while (tc--) { solve(); }

  return 0;
}