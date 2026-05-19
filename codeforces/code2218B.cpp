/*
 * Contest : Codeforces
 * Problem : 2218B - The 67th 6-7 Integer Problem
 * Link    : https://codeforces.com/contest/2218/problem/B
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

void solve() {
  int n = 7;

  int a[n], sum = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    sum += -a[i];
  }
  int ans = -INT_MAX;
  for (int i = 0; i < n; ++i) ans = max(ans, sum + 2 * a[i]);

  cout << ans << '\n';
}

int main() {
  fastio

  int tc; cin >> tc;
  while (tc--) solve();

  return 0;
}