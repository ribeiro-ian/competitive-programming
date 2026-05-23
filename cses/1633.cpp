/**
 * Contest : CSES Problem Set
 * Problem : 1633 - Dice Combinations
 * Link    : https://cses.fi/problemset/task/1633
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);
const ll MOD = 1e9 + 7;

int main() {
  fastio

  int n; cin >> n;
  vector<ll> dp(n + 1);
  dp[0] = 1;

  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= 6 && j <= i; ++j) dp[i] = (dp[i] + dp[i - j]) % MOD;
  cout << dp[n] << '\n';

  return 0;
}
