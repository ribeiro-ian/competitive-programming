/**
 * Contest : CSES Problem Set
 * Problem : 1638 - Grid Paths I
 * Link    : https://cses.fi/problemset/task/1638
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);
const int MOD = 1e9 + 7;

int main() {
  fastio

  int n; cin >> n;
  int dp[n + 1][n + 1];
  memset(dp, 0, sizeof(dp));
  dp[0][1] = 1;

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      char c; cin >> c;
      if (c != '*') dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
    }
  }
  cout << dp[n][n] << '\n';

  return 0;
}
