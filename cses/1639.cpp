/**
 * Contest : CSES Problem Set
 * Problem : 1639 - Edit Distance
 * Link    : https://cses.fi/problemset/task/1639
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int main() {
  fastio

  string s, t;
  cin >> s >> t;

  int n = s.size(), m = t.size();
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 1e9));

  dp[0][0] = 0;
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= m; ++j) {
      if (i > 0) dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
      if (j > 0) dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
      if (i > 0 && j > 0) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (s[i - 1] != t[j - 1]));
      cerr << dp[i][j] << " \n"[j == m];
    }
  }
  cout << dp[n][m] << '\n';

  return 0;
}
