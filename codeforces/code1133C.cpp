/*
  Codeforces 1133C - Balanced Team
  https://codeforces.com/problemset/problem/1133/C
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio
  int n; cin >> n;

  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];

  sort(a, a + n);

  int ans = 0;
  for (int l = 0, r = 0; l < n; l++) {
    while (r < n && abs(a[l] - a[r]) <= 5) {
      ans = max(ans, r - l + 1);
      r++;
    }
  }

  cout << ans << '\n';

  return 0;
}