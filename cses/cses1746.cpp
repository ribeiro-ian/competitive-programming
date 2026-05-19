/*
 * Contest : CSES
 * Problem : 1746 - Array Description
 * Link    : https://cses.fi/problemset/task/1746
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  const ll M = 1e9 + 7;
  ll n, m;
  cin >> n >> m;
  vector<ll> v(n);

  for (auto &i : v) cin >> i;

  vector<vector<ll>> dp(n, vector<ll>(m + 1, 0));
  if (v[0] == 0) {
    for (int i = 1; i <= m; ++i) dp[0][i] = 1;
  } else
    dp[0][v[0]] = 1;

  for (ll i = 1; i < n; ++i) {
    if (v[i] == 0) {
      for (ll x = 1; x <= m; ++x) {
        if (!dp[i - 1][x]) continue;

        for (ll j : {x - 1, x, x + 1})
          if (j >= 1 && j <= m) dp[i][j] = (dp[i][j] + dp[i - 1][x]) % M;
      }
    }
    else {
      ll x = v[i];
      for (ll j : {x - 1, x, x + 1})
        if (j >= 1 && j <= m) dp[i][x] += dp[i - 1][j] % M;
    }
  }

  ll ans = 0;
  for (ll i = 1; i <= m; ++i) ans = (ans + dp[n - 1][i]) % M;
  cout << ans << '\n';

  return 0;
}