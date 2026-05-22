/*
 * Contest : CSES Problem Set
 * Problem : 1643 - Maximum Subarray Sum
 * Link    : https://cses.fi/problemset/task/1643
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  ll n; cin >> n;
  vector<ll> a(n), dp(n + 1);
  for (auto &i : a) cin >> i;

  ll ans = -1e18;
  for (int i = 1; i <= n; i++) {
    dp[i] = max(dp[i - 1] + a[i - 1], a[i - 1]);
    ans = max(ans, dp[i]);
  }
  cout << ans << '\n';

  return 0;
}