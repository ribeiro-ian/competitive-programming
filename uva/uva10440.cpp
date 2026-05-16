/*
  UVA 10440 - Ferry Loading II
  https://vjudge.net/problem/UVA-10440
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

void solve() {
  int n, t, m, x;
  cin >> n >> t >> m;

  int a[n], time = 0, cnt = 0, trips = 0;
  for (int i = 0; i < m; ++i) cin >> a[i];

  int i = 0, time = 0, trips = 0, cnt;
  while (i < m) {
    cnt = 0;
    while (i < m && cnt < n) {
      cnt++;
      i++;
    }
    time = a[i - 1] + 2 * t;
    trips++;
  }

  cout << time - t << ' ' << trips << '\n';
}

int main() {
  fastio

  int tc; cin >> tc;
  while (tc--) solve();

  return 0;
}
