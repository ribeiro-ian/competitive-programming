/*
 * Contest : CSES Problem Set
 * Problem : 1635 - Coin Combinations I
 * Link    : https://cses.fi/problemset/task/1635
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  int n, x;
  cin >> n >> x;
  const ll MOD = 1e9 + 7;

  vector<ll> coins(n), dp(x + 1, 0);
  for (auto &i : coins) cin >> i;

  dp[0] = 1;
  for (ll i = 1; i <= x; ++i)
    for (auto &c : coins) {
      if (c > i) continue;
      ;
      dp[i] = (dp[i] + dp[i - c]) % MOD;
    }

  cout << dp[x] << '\n';

  return 0;
}
