/*
  Codeforces 101853J - Smallest Difference
  https://codeforces.com/gym/101853/problem/J
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio
  ll tc, n;

  cin >> tc;
  while (tc--) {
    cin >> n;

    ll a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a, a + n);

    ll ans = 0;
    for (ll l = 0, r = 0; l < n; l++) {
      while (r < n && abs(a[r] - a[l]) <= 1) {
        ans = max(ans, r - l + 1);
        r++;
      }
    }

    cout << ans << '\n';
  }

  return 0;
}